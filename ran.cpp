// Rắn Săn Mồi bằng C++ sử dụng raylib
// Tính năng: di chuyển, 4 bức tường (chạm là thua), tính điểm, chỉnh tốc độ, chơi lại
// Biên dịch (ví dụ):
//  Windows (MSYS2 UCRT64): g++ -std=c++17 snake_raylib.cpp -o snake.exe -O2 -lraylib -lopengl32 -lgdi32 -lwinmm
//  Linux (Debian/Ubuntu):  sudo apt install libraylib-dev && g++ -std=c++17 snake_raylib.cpp -o snake -O2 -lraylib
//  macOS (Homebrew):       brew install raylib && g++ -std=c++17 snake_raylib.cpp -o snake -O2 -lraylib

#include <raylib.h>
#include <deque>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <string>

struct Vec2i { int x; int y; };

static bool operator==(const Vec2i& a, const Vec2i& b){ return a.x==b.x && a.y==b.y; }
static Vec2i operator+(const Vec2i& a, const Vec2i& b){ return {a.x + b.x, a.y + b.y}; }

// Cấu hình lưới và cửa sổ
constexpr int CELL_SIZE   = 20;           // px mỗi ô
constexpr int GRID_COLS   = 40;           // số cột
constexpr int GRID_ROWS   = 30;           // số hàng
constexpr int SCREEN_W    = GRID_COLS * CELL_SIZE;
constexpr int SCREEN_H    = GRID_ROWS * CELL_SIZE;

// Màu sắc nhẹ nhàng
static const Color BG_DARK      = { 18, 18, 24, 255 };
static const Color GRID_LINE    = { 35, 35, 45, 255 };
static const Color SNAKE_HEAD   = {  0,180, 80, 255 };
static const Color SNAKE_BODY   = {  0,140, 60, 255 };
static const Color FOOD_COLOR   = {220, 90, 50, 255 };
static const Color WALL_COLOR   = {160,160,170,255 };
static const Color UI_TEXT      = {235,235,240,255 };
static const Color UI_MUTED     = {170,170,180,255 };

enum class GameState { MENU, PLAYING, GAME_OVER };

struct SnakeGame {
    // Trạng thái chính
    GameState state = GameState::MENU;

    // Rắn
    std::deque<Vec2i> snake;    // head ở front()
    Vec2i dir {1,0};            // hướng ban đầu: phải
    int pendingGrow = 0;        // số đốt cần nở thêm

    // Mồi
    Vec2i food {10, 10};

    // Điểm & tốc độ
    int score = 0;
    int speedLevel = 10;        // 1..20 (mặc định 10)
    float moveTimer = 0.0f;     // đếm thời gian giữa các bước di chuyển

    // Tiện ích
    bool paused = false;

    // Khởi tạo hoặc chơi lại
    void Reset() {
        snake.clear();
        snake.push_back({GRID_COLS/2, GRID_ROWS/2});
        snake.push_back({GRID_COLS/2 - 1, GRID_ROWS/2});
        snake.push_back({GRID_COLS/2 - 2, GRID_ROWS/2});
        dir = {1,0};
        pendingGrow = 0;
        score = 0;
        moveTimer = 0.0f;
        paused = false;
        SpawnFood();
    }

    // Thời gian giữa mỗi bước = 1 / speedLevel (giây)
    float StepInterval() const {
        const int clamped = speedLevel < 1 ? 1 : (speedLevel > 20 ? 20 : speedLevel);
        return 1.0f / static_cast<float>(clamped);
    }

    // Sinh mồi ở vị trí trống
    void SpawnFood(){
        while(true){
            Vec2i p { GetRandomValue(0, GRID_COLS-1), GetRandomValue(0, GRID_ROWS-1) };
            bool onSnake = std::any_of(snake.begin(), snake.end(), [&](const Vec2i& s){ return s == p; });
            if(!onSnake){ food = p; return; }
        }
    }

    // Xử lý nhập hướng, không cho quay 180 độ trực tiếp
    void HandleInputDirection(){
        Vec2i newDir = dir;
        if (IsKeyPressed(KEY_UP) || IsKeyPressed(KEY_W))      newDir = {0,-1};
        else if (IsKeyPressed(KEY_DOWN) || IsKeyPressed(KEY_S)) newDir = {0, 1};
        else if (IsKeyPressed(KEY_LEFT) || IsKeyPressed(KEY_A)) newDir = {-1,0};
        else if (IsKeyPressed(KEY_RIGHT)|| IsKeyPressed(KEY_D)) newDir = { 1,0};
        
        // Nếu độ dài > 1 thì chặn quay đầu 180°
        if (snake.size() > 1 && (newDir.x == -dir.x && newDir.y == -dir.y)) return;
        dir = newDir;
    }

    // Cập nhật một bước di chuyển của rắn
    bool Step(){
        Vec2i head = snake.front();
        Vec2i next = head + dir;

        // Va chạm tường (4 bức tường): ngoài lưới là thua
        if (next.x < 0 || next.x >= GRID_COLS || next.y < 0 || next.y >= GRID_ROWS) {
            return false; // game over
        }
        // Va chạm thân
        for (size_t i = 0; i < snake.size(); ++i) {
            if (snake[i] == next) return false;
        }

        // Tiến lên
        snake.push_front(next);

        // Ăn mồi?
        if (next == food) {
            score += 10;
            pendingGrow += 1; // nở thêm 1 đốt
            SpawnFood();
        }

        // Nếu không nở thì bỏ đuôi
        if (pendingGrow > 0) {
            pendingGrow--; 
        } else {
            snake.pop_back();
        }

        return true;
    }

    // Vẽ lưới nhẹ cho dễ định hướng
    void DrawGrid(){
        for (int x = 0; x <= GRID_COLS; ++x) {
            DrawLine(x*CELL_SIZE, 0, x*CELL_SIZE, SCREEN_H, GRID_LINE);
        }
        for (int y = 0; y <= GRID_ROWS; ++y) {
            DrawLine(0, y*CELL_SIZE, SCREEN_W, y*CELL_SIZE, GRID_LINE);
        }
    }

    // Vẽ tường (viền)
    void DrawWalls(){
        const int th = 4; // độ dày viền
        DrawRectangle(0, 0, SCREEN_W, th, WALL_COLOR);                          // top
        DrawRectangle(0, SCREEN_H - th, SCREEN_W, th, WALL_COLOR);              // bottom
        DrawRectangle(0, 0, th, SCREEN_H, WALL_COLOR);                          // left
        DrawRectangle(SCREEN_W - th, 0, th, SCREEN_H, WALL_COLOR);              // right
    }

    void DrawSnake(){
        // Vẽ thân
        bool first = true;
        for (const auto& p : snake){
            Rectangle r { static_cast<float>(p.x*CELL_SIZE), static_cast<float>(p.y*CELL_SIZE), (float)CELL_SIZE, (float)CELL_SIZE };
            DrawRectangleRounded(r, 0.2f, 4, first ? SNAKE_HEAD : SNAKE_BODY);
            first = false;
        }
    }

    void DrawFood(){
        int pad = CELL_SIZE/6; // bo góc cho đẹp
        Rectangle r { (float)(food.x*CELL_SIZE + pad), (float)(food.y*CELL_SIZE + pad), (float)(CELL_SIZE - 2*pad), (float)(CELL_SIZE - 2*pad) };
        DrawRectangleRounded(r, 0.4f, 6, FOOD_COLOR);
    }

    void DrawHUD(){
        DrawText(TextFormat("Score: %d  |  Speed: %d  |  [ ] để chỉnh tốc độ", score, speedLevel), 10, 8, 20, UI_TEXT);
        if (paused) DrawText("PAUSED (nhan P de tiep tuc)", 10, 32, 18, UI_MUTED);
    }

    void Run(){
        // MENU trước, nhấn Enter để bắt đầu
        while (!WindowShouldClose()) {
            if (state == GameState::MENU) {
                UpdateMenu();
                DrawMenu();
            } else if (state == GameState::PLAYING) {
                UpdatePlaying();
                DrawPlaying();
            } else {
                UpdateGameOver();
                DrawGameOver();
            }
        }
    }

    void UpdateMenu(){
        // Chỉnh tốc độ ở menu bằng LEFT/RIGHT
        if (IsKeyPressed(KEY_LEFT))  speedLevel = std::max(1, speedLevel - 1);
        if (IsKeyPressed(KEY_RIGHT)) speedLevel = std::min(20, speedLevel + 1);

        if (IsKeyPressed(KEY_ENTER)) {
            Reset();
            state = GameState::PLAYING;
        }
    }

    void DrawMenu(){
        BeginDrawing();
        ClearBackground(BG_DARK);
        DrawGrid();
        DrawWalls();

        const char* title = "RAN SAN MOI";
        const char* subtitle = "Muc tieu: an moi, tranh tuong & than";
        DrawText(title, SCREEN_W/2 - MeasureText(title, 48)/2, SCREEN_H/3 - 60, 48, UI_TEXT);
        DrawText(subtitle, SCREEN_W/2 - MeasureText(subtitle, 22)/2, SCREEN_H/3, 22, UI_MUTED);

        std::string sp = "Toc do: " + std::to_string(speedLevel) + "  (LEFT/RIGHT de chinh)";
        DrawText(sp.c_str(), SCREEN_W/2 - MeasureText(sp.c_str(), 24)/2, SCREEN_H/2, 24, UI_TEXT);

        const char* inst1 = "Dieu khien: WASD/Phim mui ten";
        const char* inst2 = "[ / ] giam/tang toc do  |  P tam dung";
        const char* inst3 = "ENTER de bat dau";
        DrawText(inst1, SCREEN_W/2 - MeasureText(inst1, 20)/2, SCREEN_H/2 + 40, 20, UI_MUTED);
        DrawText(inst2, SCREEN_W/2 - MeasureText(inst2, 20)/2, SCREEN_H/2 + 68, 20, UI_MUTED);
        DrawText(inst3, SCREEN_W/2 - MeasureText(inst3, 26)/2, SCREEN_H/2 + 110, 26, UI_TEXT);

        EndDrawing();
    }

    void UpdatePlaying(){
        // Pause
        if (IsKeyPressed(KEY_P)) paused = !paused;
        if (paused) return;

        HandleInputDirection();

        // Điều chỉnh tốc độ trong khi chơi
        if (IsKeyPressed(KEY_LEFT_BRACKET))  speedLevel = std::max(1, speedLevel - 1);
        if (IsKeyPressed(KEY_RIGHT_BRACKET)) speedLevel = std::min(20, speedLevel + 1);

        moveTimer += GetFrameTime();
        while (moveTimer >= StepInterval()){
            moveTimer -= StepInterval();
            if (!Step()) {
                state = GameState::GAME_OVER;
                break;
            }
        }
    }

    void DrawPlaying(){
        BeginDrawing();
        ClearBackground(BG_DARK);
        DrawGrid();
        DrawWalls();
        DrawFood();
        DrawSnake();
        DrawHUD();
        EndDrawing();
    }

    void UpdateGameOver(){
        if (IsKeyPressed(KEY_R)) {
            Reset();
            state = GameState::PLAYING; // "chơi lại"
        }
        if (IsKeyPressed(KEY_ENTER)) {
            state = GameState::MENU; // quay về menu
        }
    }

    void DrawGameOver(){
        BeginDrawing();
        ClearBackground(BG_DARK);
        DrawGrid();
        DrawWalls();

        const char* over = "GAME OVER";
        DrawText(over, SCREEN_W/2 - MeasureText(over, 64)/2, SCREEN_H/3 - 30, 64, UI_TEXT);

        std::string sc = "Diem: " + std::to_string(score);
        DrawText(sc.c_str(), SCREEN_W/2 - MeasureText(sc.c_str(), 28)/2, SCREEN_H/3 + 40, 28, UI_TEXT);

        const char* tip1 = "Nhan R de choi lai voi toc do hien tai";
        const char* tip2 = "Nhan ENTER de quay ve MENU";
        DrawText(tip1, SCREEN_W/2 - MeasureText(tip1, 22)/2, SCREEN_H/3 + 90, 22, UI_MUTED);
        DrawText(tip2, SCREEN_W/2 - MeasureText(tip2, 22)/2, SCREEN_H/3 + 118, 22, UI_MUTED);

        EndDrawing();
    }
};

int main(){
    // Khởi tạo cửa sổ
    SetConfigFlags(FLAG_WINDOW_RESIZABLE | FLAG_VSYNC_HINT);
    InitWindow(SCREEN_W, SCREEN_H, "Ran San Moi - C++ & raylib");
    SetTargetFPS(60);

    // Seed ngẫu nhiên
    SetRandomSeed((unsigned int)time(nullptr));

    SnakeGame game;
    // Ở menu ban đầu, cho người chơi chọn tốc độ rồi Enter để chơi
    while (!WindowShouldClose()){
        game.Run(); // Run có vòng lặp của riêng nó, nhưng để chắc ăn gọi trong vòng ngoài; thoát nếu user đóng.
        break;
    }

    CloseWindow();
    return 0;
}
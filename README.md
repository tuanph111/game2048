# game2048
đây là project bài tập lớn làm về game 2048 với các chức năng căn bản của game 2048 truyền thống.
* sử dụng ASDW để điều khiển các ô vuông và kết hợp các ô với nhau để đạt được điểm số tối đa (có thể vượt qua 2048).
* có file text highScore để lưu điểm cao qua các lần chơi.
* file mã nguồn được lưu trong thư mục game2048_2.
  * file MainGame.cpp bao gồm các hàm chức năng căn bản của game gồm có hàm điều khiển, các hàm để lưu điểm cao qua các lần chơi
  * file GameMenu.cpp bao gồm các hàm để tạo menu cho game gồm "Play Game" và "Exit"
  * file GameOver.cpp bao gồm các hầm để tạo menu game over cho game bao gồm hiển thị ra điểm số vừa đạt được dòng "GameOver" hai chức năng quay lại menu game ban đầu hoặc thoát ra khỏi game.
  * file loadTexture.cpp bao gồm các hàm cơ bản để load 1 texture lên screen và hàm để tạo cửa sổ của game căn bản.
  * hai file Block.cpp và DrawBlock chứa các hàm để tạo và vễ các ô trong game 2048.
  * và cuối cùng chương trình được chạy trong file main.cpp .

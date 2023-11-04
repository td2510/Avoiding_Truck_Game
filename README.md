# Avoiding_Truck_Game
Cài đặt môi trường lập trình

•	Giải nén file BGI.zip ta được các file sau: graphics.h, libbgi.a, winbgim.h.
•	Copy graphics.h và winbgim.h vào thư mục trình dịch của IDE lập trình (trong project này sử dụng Embarcadero Dev-C++).
•	Nếu sử dụng Embarcadero Dev-C++, copy graphics.h và winbgim.h vào thư mục “include” theo đường dẫn như hình dưới.
 ![image](https://github.com/td2510/Avoiding_Truck_Game/assets/111385453/348d1880-4e56-4699-ac6e-a2c973e80097)

•	Copy libbgi.a vào thư mục “lib” cùng vị trí với thư mục “include” bên trên.
 ![image](https://github.com/td2510/Avoiding_Truck_Game/assets/111385453/0443da82-b655-47b1-b7c5-2aa42977240b)


•	Mở Embarcadero Dev-C++ và chuyển thành TDM-GCC 9.2.0 32-bit Release.
 ![image](https://github.com/td2510/Avoiding_Truck_Game/assets/111385453/8d67c074-6bc4-4ac9-9432-2e99ddd613f1)


•	Chọn Tools -> Compiler Options… tích vào “Add the following commands when calling the linkers: 
 ![image](https://github.com/td2510/Avoiding_Truck_Game/assets/111385453/76b9b376-1de5-4a0b-b565-558374583505)


•	Viết thêm: -lbgi -lgdi32 -lcomdlg32 -luuid -loleaut32 -lole32 vào phần linker option bên dưới rồi nhấn OK, thư viện graphics.h đã có thể sử dụng.
 ![image](https://github.com/td2510/Avoiding_Truck_Game/assets/111385453/5b644346-079c-4014-bbc5-af565d065a16)

Giao diện trò chơi:
![image](https://github.com/td2510/Avoiding_Truck_Game/assets/111385453/d8fe4ab4-f5e1-4559-87a5-2b588a031044)
![image](https://github.com/td2510/Avoiding_Truck_Game/assets/111385453/af58962a-0863-4ca9-99b7-bc9396790d4b)


Link: https://www.youtube.com/watch?v=QHBNNf41Ya4

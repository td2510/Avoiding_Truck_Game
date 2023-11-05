# Avoiding_Truck_Game
Cài đặt môi trường lập trình

•	Giải nén file BGI.zip ta được các file sau: graphics.h, libbgi.a, winbgim.h.

•	Copy graphics.h và winbgim.h vào thư mục trình dịch của IDE lập trình (trong project này sử dụng Embarcadero Dev-C++).

•	Nếu sử dụng Embarcadero Dev-C++, copy graphics.h và winbgim.h vào thư mục “include” theo đường dẫn như hình dưới.
![image](https://github.com/td2510/Avoiding_Truck_Game/assets/111385453/cf100cfe-13cd-4a4c-b513-75529567ad9a)


•	Copy libbgi.a vào thư mục “lib” cùng vị trí với thư mục “include” bên trên.
![image](https://github.com/td2510/Avoiding_Truck_Game/assets/111385453/c857cbd7-cce0-43a7-a4f2-2626eb80234d)



•	Mở Embarcadero Dev-C++ và chuyển thành TDM-GCC 9.2.0 32-bit Release.
![image](https://github.com/td2510/Avoiding_Truck_Game/assets/111385453/b52a049b-dd67-4fa2-82ea-31d4719d5fa6)



•	Chọn Tools -> Compiler Options… tích vào “Add the following commands when calling the linkers: 
![image](https://github.com/td2510/Avoiding_Truck_Game/assets/111385453/8ba51cb3-b2e9-458b-a208-6c4251fe4ae8)



•	Viết thêm: -lbgi -lgdi32 -lcomdlg32 -luuid -loleaut32 -lole32 vào phần linker option bên dưới rồi nhấn OK, thư viện graphics.h đã có thể sử dụng.
![image](https://github.com/td2510/Avoiding_Truck_Game/assets/111385453/ef6aa781-7244-4b0b-85fd-5addccc54894)


Giao diện trò chơi:
![image](https://github.com/td2510/Avoiding_Truck_Game/assets/111385453/7f000642-7d87-4fe6-8e7c-d8ac7d8c7efb)

![image](https://github.com/td2510/Avoiding_Truck_Game/assets/111385453/96d94df7-7f1c-40f2-9b19-8929e279f981)



Link: https://www.youtube.com/watch?v=QHBNNf41Ya4

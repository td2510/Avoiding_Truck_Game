# Avoiding_Truck_Game
Setting up the programming environment

## Installation

• Unzip the BGI.zip file and you will get the following files:: graphics.h, libbgi.a, winbgim.h.

•	Copy graphics.h and winbgim.h to the compiler folder of the programming IDE (in this project we use Embarcadero Dev-C++).

•	If using Embarcadero Dev-C++, copy graphics.h and winbgim.h into the “include” folder according to the path as shown below.

![image](https://github.com/td2510/Avoiding_Truck_Game/assets/111385453/cf100cfe-13cd-4a4c-b513-75529567ad9a)


•	Copy libbgi.a into the “lib” folder in the same location as the “include” folder above.

![image](https://github.com/td2510/Avoiding_Truck_Game/assets/111385453/c857cbd7-cce0-43a7-a4f2-2626eb80234d)



•	Open Embarcadero Dev-C++ and switch to TDM-GCC 9.2.0 32-bit Release.

![image](https://github.com/td2510/Avoiding_Truck_Game/assets/111385453/b52a049b-dd67-4fa2-82ea-31d4719d5fa6)



•	Select Tools -> Compiler Options… check “Add the following commands when calling the linkers:

![image](https://github.com/td2510/Avoiding_Truck_Game/assets/111385453/8ba51cb3-b2e9-458b-a208-6c4251fe4ae8)



•	Add: -lbgi -lgdi32 -lcomdlg32 -luuid -loleaut32 -lole32 to the linker option below and click OK, the graphics.h library can now be used.

![image](https://github.com/td2510/Avoiding_Truck_Game/assets/111385453/ef6aa781-7244-4b0b-85fd-5addccc54894)


Game interface:

![image](https://github.com/td2510/Avoiding_Truck_Game/assets/111385453/7f000642-7d87-4fe6-8e7c-d8ac7d8c7efb)

![image](https://github.com/td2510/Avoiding_Truck_Game/assets/111385453/96d94df7-7f1c-40f2-9b19-8929e279f981)



Demo: https://www.youtube.com/watch?v=QHBNNf41Ya4

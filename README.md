# GlistApp
App project template for [GlistEngine](https://github.com/GlistEngine/GlistEngine)

Developers can clone this repository to initialize a new GlistEngine game project. More information can be found on the [readme](https://github.com/GlistEngine/GlistEngine/blob/main/README.md) page of GlistEngine repository.

Please clone this repo under glist/myglistapps in your GlistEngine installation directory.

## Setting up existing projects for Visual Studio

#### 1. Clone the repository to another directory via Git.

#### 2. Copy `CMakeSettings.json` to your project folder.


#### 3. Add these lines of codes to `CMakeLists.txt` above `set(APP_DIR ${CMAKE_SOURCE_DIR})` and bellow `########## DO NOT CHANGE BELOW ##########` lines. 
```cmake
if(CMAKE_BUILD_TYPE MATCHES "Debug")
	message(STATUS "CMAKE_BUILD_TYPE=${CMAKE_BUILD_TYPE}")

	if(MSVC)
		set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /Zi /Od")
	else()
		set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g")
	endif()
endif()
```

#### 4. Copy `.vs` folder to your project folder. 

## Debugging your project with Visual Studio
Project should come with "GlistApp Debug" selected by default, if not select it.
NOTE: Debugger slows your application a lot.

<img width="657" alt="image" src="https://user-images.githubusercontent.com/23135761/209318027-8cb19b52-7ef9-41cc-84f2-a383f692af2c.png">


You need to select "Run GlistApp.exe" as your target startup item as shown bellow, otherwise debugger might not work properly. 

<img width="883" alt="image" src="https://user-images.githubusercontent.com/23135761/209317591-63813cd1-519e-46fe-bc2f-4310d33a916d.png">

You can click on <img width="101" alt="image" src="https://user-images.githubusercontent.com/23135761/209242367-6dd89444-ae17-4947-84dc-cac9f8869795.png"> to run your application with the debugger attached.

## Running without debugger.
To run your project without debugger, you need to switch to "GlistApp Release" from configurations. (release builds are more optimized and debug build should not be shipped to users)

<img width="677" alt="image" src="https://user-images.githubusercontent.com/23135761/209317696-92bfec8a-5d06-44d2-bbc6-64cd563231aa.png">

Then, you need to select "Run GlistApp.exe Without Debugger" as your target startup item as shown bellow.

<img width="873" alt="image" src="https://user-images.githubusercontent.com/23135761/209317961-b7f6756a-d331-415e-bf05-d9529868a676.png">

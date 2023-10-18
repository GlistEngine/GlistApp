# GlistApp

App project template for [GlistEngine](https://github.com/GlistEngine/GlistEngine)

Developers can clone this repository to initialize a new GlistEngine game project. More information can be found on the [readme](https://github.com/GlistEngine/GlistEngine/blob/main/README.md) page of GlistEngine repository.

Please clone this repo under glist/myglistapps in your GlistEngine installation directory.

#####<u>__For iOS and MacOS builds (XCode)__</u>:

1. If you do not have Xcode, download and install before continuing the guide.

2. After cloning into the right directory, open "generate_glistapp_xcode.sh" in a text editor.

3. There is a few exposed variables available for change. The 2 most important being the `DEPLOYMENT VERSION` and the `PLATFORM`.
    - `DEPLOYMENT_VERSION` dictates the minimum iOS version the app can run at. However, due to Xcode's newer versions, only iOS version 11.0 and upwards can be run and built. We on the other hand, recommend using the 13.0 version.
    - `PLATFORM` can have 2 values. `OS64` means you are building the app for your physical phone. `SIMULATOR64COMBINED` means you are building for the iOS simulator on your Mac device.

4. After you have made appropriate changes on the bash file, you can move on to the scripts directory inside GlistApp. There, you can find 3 variables; `GLIST_IOS_DEVELOPMENT_TEAM`, `GLIST_IOS_PRODUCT_BUNDLE_IDENTIFIER` and `GLIST_IOS_PRODUCT_NAME`.
    - You have to write down your Apple Development Team ID next to `GLIST_IOS_DEVELOPMENT_TEAM`,
    - Your app's product bundle identifier next to`GLIST_IOS_PRODUCT_BUNDLE_IDENTIFIER`.
    - And your App's desired name next to `GLIST_IOS_PRODUCT_NAME`.

5. After everything is to your liking, you can run the "generate_glistapp_xcode.sh" with the following command in commandline

    `sh generate_glistapp_xcode.sh`

6. When Xcode opens the project, click on ALL_BUILD where it says `ALL_BUILD > My Mac` at the top center of the Xcode screen and select `GlistApp`.

7. Click on the run button at the top-left of the screen.

##### Troubleshooting and FAQ

- Receiving linking/linker errors:

Most of the linker errors are usually caused by selecting the wrong platform. that is, selecting SIMULATOR64COMBINED for usage in your phone and vice-versa. Please select the correct platform for your usage.

- Even after I changed the platform, the program still experiences linking errors!

You have to remove the old _build folder in order for changes to take effect in your new Xcode project created entirely with your new settings. This is for almost everything you change inside `generate_glistapp_xcode.sh` file.

- Why does my files that I created inside Xcode doesn't get included in the compilation?

This is because how CMake creates Xcode projects and how Xcode handles files. Xcode has its own file management and compilation system in which you have to supply your source files into a type of list. To avoid doing that, create your new source and header files outside of Xcode (either from your terminal or the "Finder" program), then add these files to the `GlistApp_SOURCES` and `GlistApp_HEADERS` variables inside CMakeLists.txt. Then you have to re-run (Step.5) the bash file.

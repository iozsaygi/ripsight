<p align="center">
  <a href="#"><img src="https://github.com/iozsaygi/ripsight/blob/master/_media/preview.gif"/></a>
</p>

## About
Ripsight is a 2D Top-Down-Shooter game which built with custom game engine in 22 days. </br>
The engine supports the "Entity Component" architecture and built on top of SDL library. </br> </br>
The game eventually became somewhat moddable, player can change the in-game visuals/effects by changing the files in "assets" folder. </br>

## Dependencies
  * [SDL2](https://www.libsdl.org/)
  * [SDL_image](https://www.libsdl.org/projects/SDL_image/)
  * [SDL_mixer](https://www.libsdl.org/projects/SDL_mixer/index.html)
  * [SDL_ttf](https://www.libsdl.org/projects/SDL_ttf/)

## Building
  * <b>Windows</b>
    * Download the [Visual Studio Community 2019](https://visualstudio.microsoft.com/) (Make sure to install "Desktop development with C++")
    * Clone the repository
    * Download all the dependencies required and put them all in "dependencies" folder
    * Make sure "dependencies" folder is at the same location with ".sln" file of project
    * Build the project inside Visual Studio
    * Copy and paste the "assets" folder to the same location with the ".exe" file
    
    This is how your general folder structure should looks like (After build)
    
        .
        ├── _media 
        ├── assets
        ├── build          
        ├── dependencies
        ├── engine
        ├── ripsight
        ├── .gitignore
        ├── LICENSE
        ├── README.md
        └── ripsight.sln
  
## Credits
  * <b>Programming</b>
    * Ismail Ozsaygi
  * <b>Art</b>
    * Kenney
    * hassekf
    * PWL
  * <b>Audio</b>
    * Michael Baradari
  
## License
[MIT License](https://github.com/iozsaygi/ripsight/blob/master/LICENSE)

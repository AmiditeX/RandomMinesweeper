# RandomMinesweeper

This project is a C++, Qt-based application to generate a random map of Minesweeper using a pseudo-random generator, the Linear Congruential Generator.  
You can choose your own settings for the LCG, and when pressing the Generate button, the seed used by generator will be the timestamp at the moment you generated it. Once the grid is generated, you can guess the position of mines by using the Resolver application.  
To use the Resolver, input the same LCG settings as the one used to generate the grid, and input the same seed that was used to generate the grid. A solved grid will appear in the resolver with all the positions of mines. Be careful, the grid has to be read from top to bottom on the Resolver, but indicates the position from bottom to top on the Minesweeper.  
The point of those applications is to prove that pseudo-random generators are predictable if the initial seed used is known, and if the parameters of the LCG are known (which is easy to guess from the compiler/language used).  
That way, a cryptographic key generated with a pseudo-random generator could be deducted easily just by knowning when it was generated if the LCG used a timestamp as an input seed (which is often the case).

You can input your own settings to the LCG, including the seed, modulo, multiplier, increment, and the number of bit to shift.
You can test parameters from various languages and compilers provided here :  
https://en.wikipedia.org/wiki/Linear_congruential_generator#Parameters_in_common_use.  

## Download the project

This project was compiled with MinGW 32 bits using Qt Creator. It uses the Qt library and is available under the MIT licence. 
A precompiled version is available at: https://sourceforge.net/projects/randomminesweeper/  

## Building it yourself

If you want to compile the project on your own, you'll need Qt with QMake, and a C++ compiler.  
Your best option is to open the BitmapGenerator.pro using Qt Creator. It will auto-configure the project using QMake, asking you only to setup a compiler. You'll be able to edit the code and the GUI using the UI designer integrated in Qt Creator.  
To ship it, you'll need a few DLL from the Qt library. Your best choice here would be to use the windeployqt tool provided with Qt for it to copy automatically all the needed DLL without you having to find them one by one.  

### Linked project

A bitmap generator using the LCG to assess the quality of randomness : https://github.com/AmiditeX/RandomBitmapGenerator/

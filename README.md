 ![Logo Hangman Terminal Edition](Logo.png)                 

# Deployment
## Arm Cortex-M4 Base Project
Example Workspace für die Vorlesung Systemnahe Programmierung 2 an der
DHWB Ravensburg.

### Arm Documentation
 - [Cortex M4 Startseite](https://developer.arm.com/Processors/Cortex-M4)
 - [ARMv7-M Architecture Reference Manual](https://developer.arm.com/documentation/ddi0403/latest/)
 - [Cortex-M4 Devices Generic User Guide](https://developer.arm.com/documentation/dui0553/b/?lang=en)
 - [Arm Cortex-M4 Processor Technical Reference Manual Revision r0p1](https://developer.arm.com/documentation/100166/0001/?lang=en)
 - [Arm Application Binary Interface](https://github.com/ARM-software/abi-aa)
 - [GNU Assembler Documentation](https://sourceware.org/binutils/docs-2.40/as/index.html)
 - [GNU Linker Documentation](https://sourceware.org/binutils/docs-2.40/ld/index.html)

### Prerequisites
 - CMake
 - Arm GCC Cross-Compiler
 - Wind River Simics

### Building
Auschecken des Quellcodes:
`git clone https://github.com/infohoschie/Arm-Cortex-M4-Base.git`

Erstellen des Build:
 - Mittels CMake Presets:
   ```cmake --preset arm-cortex-m4```
 - Klassisch:
   ```cmake -B build -S . -DCMAKE_BUILD_TYPE=Debug -DCMAKE_TOOLCHAIN_FILE=toolchain.cmake```
 - Caro:
   ```cmake --preset arm-cortex-m4 -G "Unix Makefiles"```

Bauen:
 - Mittels CMake Presets:
   ```cmake --build --preset arm-cortex-m4```
 - Klassisch:
   ```cmake --build build .```
      
Neue .c files immer in CmakeList.txt einfügen unter "target_sources"
 
### Running in Wind River Simics
Install Wind River Simics (Currently only for Windows and Linux available)

**Note**
For Linux installation assure, that I386 Support is available, e.g. for 
Ubuntu/ Debian: ```sudo dpkg --add-architecture i386```

Propagate the License Server via environment variable:
```SIMICS_LICENSE_FILE=27000@wrs-lizenz.inf.dhbw-ravensburg.de```

Start Simics, e.g. via command-line:
```<SIMICS_INSTALL>/bin/simics6_22_12/simics-6/simics-6.0.154/bin/simics-eclipse```
Create Simics Workspace

Create Simics Project: File -> New -> Simics Project

Via Tab *Simics Control* create new *Simics Session*.
Select *Target System*: *arm-cortex-m4-ref - cortex-m4-ref-helloworld*
Modify *Parameters*: *Runtime* -> *demo_image* set to built binary
Select *Start as debug session*



# Project Conventions

## IDEs

 - Jetbrains CLion
   Das Projekt kann direkt in der IDE geöffnet (ausgechecked) werden.
   Die CMake Presets werden direkt als build-target angeboten

 - Visual Studio Code

## Agreements
 - Language: English

## Tools
 - ASCII Art: http://www.patorjk.com/software/taag/#p=display&h=3&f=Standard&t=You%20%20%20win%20!%0A%0A
 - Font: Big



# User Manual

## Start
Start the simics project, press F6 and switch to the serial console. Press "s" or "S" to start the game.

You can now type a word that you want your friends to guess. Of course, your word won't show so that your friends won't see it. Remember not to use special characters such as "ä, ö, ü" or punctuation characters. Don't care about case-sensitivity, lower-case letters and capital letters are fine. To confirm your word, press "Enter".

TODO Spielablauf

In case you need inspiration for good guessing words, check out the "word_inspo_A" and "word_inspo_B". The lists contain different words, so you can play in turns without using the same words.

## Game
Now the player is in turn. Type in the letters you expect in the word. You'll be shown the letters you tried underneath the graphic and the letters you already guessed correct.

TODO Rundenzeit

## End
The game will guido you through all the options you have in order to play again or quit the game. Once you decide to finish playing, you'll ...

TODO How to 
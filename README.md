# ObsCompare
Short Comparison of different object/observer systems in C++

## Supported OSes
* MacOS
* Linux
* Windows (not tested)

## Compiling
You'll need just two libraries: boost and Qt.  You can download Qt here ( http://www.qt.io/download-open-source/ ) or simply use your distribution's tools.

### On Ubuntu
sudo aptitude install qtsystems5-dev
sudo apt-get install libboost-all-dev
sudo apt-get install qtchooser
export QT_SELECT=qt5

### Compilation commands (same for all platforms)
./buildAll.pl (requires Perl)
or
Use Qt Creator to open the .pro files

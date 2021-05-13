mkdir src inc bin
wget https://raw.githubusercontent.com/chrabri2/NASA_Preternship_Project/main/Makefile
make initialize
wget https://raw.githubusercontent.com/chrabri2/NASA_Preternship_Project/main/solutions.csv
wget https://raw.githubusercontent.com/chrabri2/NASA_Preternship_Project/main/vendor.csv

wget https://raw.githubusercontent.com/chrabri2/NASA_Preternship_Project/main/inc/CSVReader.h
cp CSVReader.h inc/CSVReader.h
rm CSVReader.h

wget https://raw.githubusercontent.com/chrabri2/NASA_Preternship_Project/main/inc/DLList.h
cp DLList.h inc/DLList.h
rm DLList.h

wget https://raw.githubusercontent.com/chrabri2/NASA_Preternship_Project/main/inc/MaxPriorityQueue.h
cp MaxPriorityQueue.h inc/MaxPriorityQueue.h
rm MaxPriorityQueue.h

wget https://raw.githubusercontent.com/chrabri2/NASA_Preternship_Project/main/inc/Member.h
cp Member.h inc/Member.h
rm Member.h

wget https://raw.githubusercontent.com/chrabri2/NASA_Preternship_Project/main/inc/MinPriorityQueue.h
cp MinPriorityQueue.h inc/MinPriorityQueue.h
rm MinPriorityQueue.h

wget https://raw.githubusercontent.com/chrabri2/NASA_Preternship_Project/main/inc/Node.h
cp Node.h inc/Node.h
rm Node.h

wget https://raw.githubusercontent.com/chrabri2/NASA_Preternship_Project/main/inc/Owner.h
cp Owner.h inc/Owner.h
rm Owner.h

wget https://raw.githubusercontent.com/chrabri2/NASA_Preternship_Project/main/inc/Player.h
cp Player.h inc/Player.h
rm Player.h

wget https://raw.githubusercontent.com/chrabri2/NASA_Preternship_Project/main/inc/gfx3.h
cp gfx3.h inc/gfx3.h
rm gfx3.h

wget https://raw.githubusercontent.com/chrabri2/NASA_Preternship_Project/main/inc/graphics.h
cp graphics.h inc/graphics.h
rm graphics.h

wget https://github.com/chrabri2/NASA_Preternship_Project/raw/main/bin/gfx3.o
cp gfx3.o bin/gfx3.o
rm gfx3.o

wget https://raw.githubusercontent.com/chrabri2/NASA_Preternship_Project/main/src/CoECISimulator.cpp
cp CoECISimulator.cpp src/CoECISimulator.cpp
rm CoECISimulator.cpp

wget https://raw.githubusercontent.com/chrabri2/NASA_Preternship_Project/main/src/graphics.cpp
cp graphics.cpp src/graphics.cpp
rm graphics.cpp

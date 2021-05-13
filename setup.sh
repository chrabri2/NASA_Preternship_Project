mkdir src inc
wget https://raw.githubusercontent.com/chrabri2/NASA_Preternship_Project/no_gfx/Makefile
make initialize
wget https://raw.githubusercontent.com/chrabri2/NASA_Preternship_Project/no_gfx/solutions.csv
wget https://raw.githubusercontent.com/chrabri2/NASA_Preternship_Project/no_gfx/vendor.csv

wget https://raw.githubusercontent.com/chrabri2/NASA_Preternship_Project/no_gfx/inc/CSVReader.h
cp CSVReader.h inc/CSVReader.h
rm CSVReader.h

wget https://raw.githubusercontent.com/chrabri2/NASA_Preternship_Project/no_gfx/inc/DLList.h
cp DLList.h inc/DLList.h
rm DLList.h

wget https://raw.githubusercontent.com/chrabri2/NASA_Preternship_Project/no_gfx/inc/MaxPriorityQueue.h
cp MaxPriorityQueue.h inc/MaxPriorityQueue.h
rm MaxPriorityQueue.h

wget https://raw.githubusercontent.com/chrabri2/NASA_Preternship_Project/no_gfx/inc/Member.h
cp Member.h inc/Member.h
rm Member.h

wget https://raw.githubusercontent.com/chrabri2/NASA_Preternship_Project/no_gfx/inc/MinPriorityQueue.h
cp MinPriorityQueue.h inc/MinPriorityQueue.h
rm MinPriorityQueue.h

wget https://raw.githubusercontent.com/chrabri2/NASA_Preternship_Project/no_gfx/inc/Node.h
cp Node.h inc/Node.h
rm Node.h

wget https://raw.githubusercontent.com/chrabri2/NASA_Preternship_Project/no_gfx/inc/Owner.h
cp Owner.h inc/Owner.h
rm Owner.h

wget https://raw.githubusercontent.com/chrabri2/NASA_Preternship_Project/no_gfx/inc/Player.h
cp Player.h inc/Player.h
rm Player.h

wget https://raw.githubusercontent.com/chrabri2/NASA_Preternship_Project/no_gfx/src/CoECISimulator.cpp
cp CoECISimulator.cpp src/CoECISimulator.cpp
rm CoECISimulator.cpp


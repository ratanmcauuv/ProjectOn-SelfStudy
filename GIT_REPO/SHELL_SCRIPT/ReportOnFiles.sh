#! /bin/bash

find /media/sf_SOURCE_CODE -iname "*.cpp" -print > ./all_cpp_files.txt

echo "FILE_NAME                  SIZE_OF_FILE    LINE_NUM    WORD_COUNT     CHAR_COUNT"
echo "--------------------------------------------------------------------------------"
for fn in `cat all_cpp_files.txt`
do
	file_size=`ls -l $fn | awk '{print $5}'`
	line_num=`cat $fn | wc -l`
	word_count=`cat $fn | wc -w`
	char_count=`cat $fn | wc -c`
	#echo "`basename $fn`       $file_size     $line_num       $word_count      $char_count"
	printf " %-25s    %-10d     %-10d   %-10d   %-10d \n" `basename $fn` $file_size $line_num $word_count $char_count
	
done
echo "--------------------------------------------------------------------------------"


#   SHELL $
#   SHELL $./ReportOnFiles.sh 
#   FILE_NAME                  SIZE_OF_FILE    LINE_NUM    WORD_COUNT     CHAR_COUNT
#   --------------------------------------------------------------------------------
#    CheckCpp17Features.cpp       931            39           118          931        
#    LamdaFunc.cpp                417            18           44           417        
#    MemLeak.cpp                  431            16           64           431        
#    YoutubeChannel.cpp           4550           174          417          4550       
#    AbstractFactoryTest.cpp      2732           117          286          2732       
#    AbsCar.cpp                   74             2            10           74         
#    AbsVehicleFactory.cpp        127            4            9            127        
#    AutoMobileFactory.cpp        450            14           36           450        
#    Mahindra.cpp                 261            10           27           261        
#    MahindraCar.cpp              187            8            22           187        
#    TataCar.cpp                  168            8            23           168        
#    TataMotors.cpp               263            11           27           263        
#    VehicleClient.cpp            593            22           57           593        
#    FactoryPattern.cpp           1083           54           130          1083       
#    Bike.cpp                     147            8            20           147        
#    Bus.cpp                      141            8            20           141        
#    Car.cpp                      141            8            20           141        
#    Tempo.cpp                    153            8            20           153        
#    Vehicle.cpp                  84             4            10           84         
#    VehicleFactory.cpp           508            19           58           508        
#    VehicleClient.cpp            416            20           45           416        
#    Logger.cpp                   1938           91           218          1938       
#    Logger2.cpp                  1720           75           203          1720       
#    SingletonPattern.cpp         1594           68           154          1594       
#    VectorSort.cpp               400            20           46           400        
#   --------------------------------------------------------------------------------
#   SHELL $



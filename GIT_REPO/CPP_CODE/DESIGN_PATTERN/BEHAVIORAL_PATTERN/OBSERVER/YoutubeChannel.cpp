#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

//Forward Declaration
class ISubScriber;
class Subscriber;

/*================== Publisher ==================*/
class Video
{
 public:
    Video(string videoName, int length, int size) : videoName_(videoName),
      length_(length), 
      size_(size) {
        std::cout << "Video()\n";
    }
    void getVideoInfo() const{
        std::cout << "Video name :::: " << videoName_ << "\n"
                    <<"Length ::: " << length_ << " mins\n"
                    << "size ::: " << size_ << " MB\n\n";
    }
    ~Video() { std::cout << "~Video()\n"; }      
 private:
    string videoName_;
    int length_;
    int size_;
};

class YoutubeChanel
{
 public:
    YoutubeChanel(string chanelName) : ChanelName_(chanelName) {
        std::cout << "YoutubeChanel()\n";
    }
    void registerToChanel(ISubScriber *iSub) {
        subscribersList.push_back(iSub);
    }
    void unReisteredFromChanel(int subId) {
        std::remove_if(subscribersList.begin(), subscribersList.end(), [=](auto iSub){
            return iSub->getSubscriberId() == subId;
        });
    }
    void NotifyToAllSubScribers(Video *video) {
         for_each(subscribersList.begin(), subscribersList.end(), [&](auto sub) {
            sub->updateLatestVedio(video);
         });
    }
    void addVideo(Video *video) {
        videoCollection.push_back(video);
    }
    int getTotalNumbersOfVideosInChannel() {
        return videoCollection.size();
    }
    ~YoutubeChanel() {
        std::cout << "~YoutubeChanel()\n";
    }
 private:
    std::vector<ISubScriber *> subscribersList;
    std::vector<Video *> videoCollection; 
    string ChanelName_;
};

class ContentCreator
{
 public:
    ContentCreator(const string &name, YoutubeChanel *ytChanel) : name_(name), 
        ytChanel_(ytChanel) {
        std::cout << "ContentCreator()\n";
    }
    ~ContentCreator() 
    {
        std::cout << "~ContentCreator()\n";
        if(ytChanel_ != nullptr) {
            delete ytChanel_;
            ytChanel_ = nullptr;
        }
    }
    void createNewVideo(string videoName, int length, int size) { 
       video_.push_back(new  Video(videoName, length, size)); 
    }
    void UploadNewVideo() {
        ytChanel_->addVideo(video_.back());
        ytChanel_->NotifyToAllSubScribers(video_.back());
    }
 private:
    string name_;
    YoutubeChanel *ytChanel_;
    std::vector<Video *> video_;
};

/*================== Subscriber ==================*/
class ISubScriber
{
 public:
    virtual void updateLatestVedio(Video *video) = 0;
    virtual void getSubscriberedInfo() const= 0;
    virtual int getSubscriberId() const = 0;
    virtual ~ISubScriber() = 0;
};

ISubScriber :: ~ISubScriber() {
    std::cout << "~ISubScriber()\n";
}

class Subscriber : public ISubScriber
{
 public:
    Subscriber(int SubscriberId, string name, int age, string profession, string address) : 
        SubscriberId_(SubscriberId),
        name_(name),
        age_(age),
        profession_(profession),
        address_(address) 
    {
        std::cout << "Subscriber()\n";
    }

    void updateLatestVedio(Video *video) {
        std::cout << "Latest Video uploade\n";
        video_ = video;
    }

    void getSubscriberedInfo() const
    {
        std::cout << "Name :: " << getName() << "\nSubscriber Id : " << getSubscriberId() << std::endl;
        if(video_ != nullptr) {
            video_->getVideoInfo();
        }
    }
    //Getter Methods
    int getSubscriberId() const { return SubscriberId_; }
    string getName() const { return name_; }
    int getAge() const { return age_; }
    string getProfession() const { return profession_; }
    string address() const { return address_; }
 private:
    Video *video_;
    int SubscriberId_;
    string name_;
    int age_;
    string profession_;
    string address_;
};

//Client
int main()
{
    //ContentCreator Prospective
    YoutubeChanel *YC = new YoutubeChanel("GeoPolitics");
    std::cout << "Total Videos in Channel :::: "<< YC->getTotalNumbersOfVideosInChannel() << std::endl;
    ContentCreator CC("Rakesh", YC);
    
    //Subscriber Prospective
    Subscriber *sub_1 = new Subscriber(123, "XXX", 23, "Student", "Banhgalore");
    Subscriber *sub_2 = new Subscriber(125, "YYY", 30, "Professional", "Hydrabad");

    YC->registerToChanel(sub_1);
    YC->registerToChanel(sub_2);
   
    CC.createNewVideo("Travel to Goa", 34, 200);
    CC.UploadNewVideo();
    std::cout << "Total Videos in Channel :::: "<< YC->getTotalNumbersOfVideosInChannel() << std::endl;
    Subscriber *sub_3 = new Subscriber(232, "ZZZZ", 31, "Professor", "Cuttack");
    YC->registerToChanel(sub_3);

    //Get the Updated information from the Subscribers
    sub_1->getSubscriberedInfo();
    sub_2->getSubscriberedInfo();
    sub_3->getSubscriberedInfo();

    CC.createNewVideo("Travel to Delhi", 60, 223);
    std::cout << "---------------Unsubscribe from YOUTUBE channel-----------------\n";
    YC->unReisteredFromChanel(125);
    
    std::cout << "----- New Video uploaed !!! ----\n";
    CC.createNewVideo("Travel to Delhi", 60, 223);
    CC.UploadNewVideo();
    std::cout << "Total Videos in Channel :::: "<< YC->getTotalNumbersOfVideosInChannel() << std::endl;

    std::cout << "----- Collecting information from all Subscriber ---- \n";
    sub_1->getSubscriberedInfo();
    sub_2->getSubscriberedInfo();
    sub_3->getSubscriberedInfo();

    delete sub_1;
    delete sub_2;
    delete sub_3;

    return 0;
}
#include "show.h"

namespace streaming
{
  show::show():video()
  {
    ;
  }

  show::show(
    std::string_view id, std::string_view type, std::string_view title, 
    std::string_view director, std::string_view country, std::string_view year, 
    std::string_view rating, std::string_view duration, 
    std::string_view description, double score
  ) : video(
    id, type, title, director, country, year, rating, duration, description, 
    score
  )
  {
    ;
  }

  void show::operator=(double score)
  {
    this -> setStars(score);
  }

  void show::fileReader(const rapidcsv::Document file, const std::string& id)
  {
    size_t titles {file.GetRowCount()};

    for (int title {0}; title < titles; ++title)
    {
      std::vector<std::string> showData {file.GetRow<std::string>(title)};
            
      if ((showData[0] == id) && (showData[1] == "TV Show"))
      {
        this -> setVideoID(showData[0]);  
        this -> setVideoType(showData[1]);
        this -> setVideoTitle(showData[2]);
        this -> setVideoDirector(showData[3]);
        this -> setVideoCountry(showData[5]);
        this -> setReleaseYear(showData[7]);
        this -> setRating(showData[8]);
        this -> setDuration(showData[9]);
        this -> setVideoDescription(showData[11]);

        this -> dataDisplayer();
      }
      else if ((showData[0] == id) && (showData[1] != "TV Show"))
      {
        std::cout << "Lo sentimos! Tu identificador le pertenecia a una pelicula, aqui esta un show elegido aleatoriamente\n";
        bool validity {true};

        while (validity)
        {
          const int backupIndex {backupContent(1, titles)};
          std::string backupType {file.GetCell<std::string>("type", backupIndex)};                    
          if (backupType == "TV Show")
          {
            std::vector<std::string> backupData {file.GetRow<std::string>(backupIndex)};
                    
            this -> setVideoID(backupData[0]);  
            this -> setVideoType(backupData[1]);
            this -> setVideoTitle(backupData[2]);
            this -> setVideoDirector(backupData[3]);
            this -> setVideoCountry(backupData[5]);
            this -> setReleaseYear(backupData[7]);
            this -> setRating(backupData[8]);
            this -> setDuration(backupData[9]);
            this -> setVideoDescription(backupData[11]);

            this -> dataDisplayer();
          }
          validity = (backupType != "TV Show");
        }
      }
    }
  }
}
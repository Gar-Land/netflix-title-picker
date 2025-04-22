#include "movie.h"

namespace streaming
{
  movie::movie():video()
  {
    ;
  }

  movie::movie(
    std::string_view id, std::string_view type, std::string_view title, 
    std::string_view director, std::string_view country, 
    std::string_view year, std::string_view rating, std::string_view duration, 
    std::string_view description, double score
  ) : video(
    id, type, title, director, country, year, rating, duration, description, 
    score
  )
  {
    ;
  }

  void movie::operator=(double score)
  {
    this -> setStars(score);
  }

  void movie::fileReader(const rapidcsv::Document file, const std::string& id)
  {
    size_t titles {file.GetRowCount()};

    for (int title {0}; title < titles; ++title)
    {
      std::vector<std::string> movieData {file.GetRow<std::string>(title)};
            
      if ((movieData[0] == id) && (movieData[1] == "Movie"))
      {
        this -> setVideoID(movieData[0]);  
        this -> setVideoType(movieData[1]);
        this -> setVideoTitle(movieData[2]);
        this -> setVideoDirector(movieData[3]);
        this -> setVideoCountry(movieData[5]);
        this -> setReleaseYear(movieData[7]);
        this -> setRating(movieData[8]);
        this -> setDuration(movieData[9]);
        this -> setVideoDescription(movieData[11]);

        this -> dataDisplayer();
      }
      else if ((movieData[0] == id) && (movieData[1] != "Movie"))
      {
        std::cout << "Lo sentimos! Tu identificador le pertenecia a un show, aqui esta una pelicula elegida aleatoriamente\n";
        bool validity {true};

        while (validity)
        {
          int backupIndex {backupContent(1, titles)};
          std::string backupType {file.GetCell<std::string>("type", backupIndex)};
                    
          if (backupType == "Movie")
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
          validity = (backupType != "Movie");
        }
      }
    }
  }
}
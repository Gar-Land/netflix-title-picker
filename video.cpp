#include "video.h"

namespace streaming
{
  video::video()
  {
    this -> videoID = " ";
    this -> videoType = " ";
    this -> videoTitle = " ";

    this -> videoDirector = " ";
    this -> videoCountry = " ";
    this -> releaseYear = " ";

    this -> videoRating = " ";
    this -> videoDuration = " ";
    this -> videoDescription = " ";

    this -> stars = 0.0;
  }

  video::video(
    std::string_view id, std::string_view type, std::string_view title, 
    std::string_view director, std::string_view country, std::string_view year, 
    std::string_view rating, std::string_view duration, std::string_view description, 
    double score
  )
  {
    this -> videoID = id;
    this -> videoType = type;
    this -> videoTitle = title;

    this -> videoDirector = director;
    this -> videoCountry = country;
    this -> releaseYear = year;

    this -> videoRating = rating;
    this -> videoDuration = duration;
    this -> videoDescription = description;

    this -> stars = score;
  }

  void video::setVideoID(const std::string_view& id)
  {
    this -> videoID = id;
  }
  std::string_view video::getVideoID()
  {
    return videoID;
  }

  void video::setVideoType(const std::string_view& type)
  {
    this -> videoType = type;
  }
  std::string_view video::getVideoType()
  {
    return videoType;
  }

  void video::setVideoTitle(const std::string_view& title)
  {
    this -> videoTitle = title;
  }
  std::string_view video::getVideoTitle()
  {
    return videoTitle;
  }

  void video::setVideoDirector(const std::string_view& director)
  {
    this -> videoDirector = director;
  }
  std::string_view video::getVideoDirector()
  {
    return videoDirector;
  }

  void video::setVideoCountry(const std::string_view& country)
  {
    this -> videoCountry = country;
  }
  std::string_view video::getVideoCountry()
  {
    return videoCountry;
  }

  void video::setReleaseYear(const std::string_view& year)
  {
    this -> releaseYear = year;
  }
  std::string_view video::getReleaseYear()
  {
    return releaseYear;
  }

  void video::setRating(const std::string_view& rating)
  {
    this -> videoRating = rating;
  }
  std::string_view video::getRating()
  {
    return videoRating;
  }

  void video::setDuration(const std::string_view& duration)
  {
    this -> videoDuration = duration;
  }
  std::string_view video::getDuration()
  {
    return videoDuration;
  }

  void video::setVideoDescription(const std::string_view& description)
  {
    this -> videoDescription = description;
  }
  std::string_view video::getVideoDescription()
  {
    return videoDescription;
  }

  void video::setStars(double score)
  {
    this -> stars = score;
  }
  double video::getStars()
  {
    return stars;
  }

  void video::dataDisplayer()
  {
    std::cout << "\nID: " << videoID << "\tTitulo: " << videoTitle << '\n';
    std::cout << "Director: " << videoDirector << "\tPais: " << videoCountry << '\n';
    std::cout << "Anho de lanzamiento: " << releaseYear << "\tRating: " << videoRating << "\tDuracion: " << videoDuration << '\n';
    std::cout << "Descripcion: " << videoDescription << '\n';
  }

  void video::fileReader(const rapidcsv::Document file, const std::string& id)
  {
    ;   
  }
}
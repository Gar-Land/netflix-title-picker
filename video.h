#ifndef VIDEO_H
#define VIDEO_H

#include <algorithm>
#include <cmath>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

#include "rapidcsv.h"
#include "random.h"

namespace streaming
{
  class video
  {
    private:
      std::string_view videoID;
      std::string_view videoType;
      std::string_view videoTitle;

      std::string_view videoDirector;
      std::string_view videoCountry;
      std::string_view releaseYear;

      std::string_view videoRating;
      std::string_view videoDuration;
      std::string_view videoDescription;

      double stars;

    public:
      video();
      video(
        std::string_view id, std::string_view type, std::string_view title, 
        std::string_view director, std::string_view country, 
        std::string_view year, std::string_view rating, 
        std::string_view duration, std::string_view description, double score
      );

      void setVideoID(const std::string_view& id);
      std::string_view getVideoID();

      void setVideoType(const std::string_view& type);
      std::string_view getVideoType();

      void setVideoTitle(const std::string_view& title);
      std::string_view getVideoTitle();

      void setVideoDirector(const std::string_view& director);
      std::string_view getVideoDirector();

      void setVideoCountry(const std::string_view& country);
      std::string_view getVideoCountry();

      void setReleaseYear(const std::string_view& year);
      std::string_view getReleaseYear();

      void setRating(const std::string_view& rating);
      std::string_view getRating();

      void setDuration(const std::string_view& duration);
      std::string_view getDuration();

      void setVideoDescription(const std::string_view& description);
      std::string_view getVideoDescription();

      void setStars(double score);
      double getStars();

      void dataDisplayer();

      virtual void fileReader(
        const rapidcsv::Document file, const std::string& id
      ) = 0;
  };
}

#endif
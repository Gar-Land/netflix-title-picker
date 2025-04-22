#ifndef MOVIE_H
#define MOVIE_H

#include "video.h"

namespace streaming
{
  class movie : public video
  {
    public:
      movie();
      movie(
        std::string_view id, std::string_view type, std::string_view title, 
        std::string_view director, std::string_view country, 
        std::string_view year, std::string_view rating, 
        std::string_view duration, std::string_view description, double score
      );

      void operator=(double score);

      void fileReader(const rapidcsv::Document file, const std::string& id);
  };
}

#endif
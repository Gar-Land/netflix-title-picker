#include "movie.h"
#include "show.h"

namespace
{   
  char userInput()
  {
    char userChoice {};
    bool validity {true};

    while (validity)
    {   
      std::cout << "DESPLEGADOR DE INFORMACION DE NETFLIX\nContinuar (Y/N): ";
      std::cin >> userChoice;
      std::cout << '\n';

      validity = ((userChoice != 'Y') && (userChoice != 'N'));
    }

    return userChoice;
  }

  void titleRecollector(const rapidcsv::Document file, int option)
  {
    int titles {};
    std::cout << "De cuantas quisieras desplegar informacion? ";
    std::cin >> titles;

    std::string id {};
    std::cout << "\nLos IDs empiezan con el caracter 's' seguido de un numero\n";

    double userStars {};
    if (option == 1)
    {
      for (int jjj {0}; jjj < titles; ++jjj)
      {
        std::cout << "\nID de tu pelicula: ";
        std::getline(std::cin >> std::ws, id);
        std::cout << '\n';

        streaming::movie movie;
        movie.fileReader(file, id);
                            
        std::cout << "\nQue puntaje, en estrellas, le daras? ";
        std::cin >> userStars;

        std::cout << "......";

        movie = userStars;
        std::cout << "\nSe ha actualizado el puntaje: " << movie.getStars() << '\n';
      }
    }
    else
    {
      for (int kkk {0}; kkk < titles; ++kkk)
      {
        std::cout << "\nID de tu show: ";
        std::getline(std::cin >> std::ws, id);
        std::cout << '\n';

        streaming::show show;
        show.fileReader(file, id);

        std::cout << "\nQue puntaje, en estrellas, le daras? ";
        std::cin >> userStars;

        std::cout << "......";

        show = userStars;
        std::cout << "\nSe ha actualizado el puntaje: " << show.getStars() << '\n';
      }
    }
  }

  void optionsMenu(char choice, const rapidcsv::Document file)
  {   
    std::cout << "DISFRUTA DE 8807 PELICULAS Y SHOWS!\n";

    if (choice == 'Y')
    {
      int displayOption {};
      std::cout << "1) Peliculas\n2) Shows\nQue desplegaras?: ";
      std::cin >> displayOption;

      switch (displayOption)
      {
        case 1:
        case 2:
          titleRecollector(file, displayOption);
          break;
        default:
        optionsMenu(choice, file);
          break;
      }
    }
    else
      ;
  }
}

int main()
{
  /* 
    rapidcsv::LabelParams(0, -1);  
    rapidcsv::SeparatorParams(
      ',', false, rapidcsv::sPlatformHasCR, false, true, '"'
    );  
    rapidcsv::ConverterParams(true); 
    rapidcsv::LineReaderParams(); 
  */

  rapidcsv::Document file(
    "netflix_titles.csv", rapidcsv::LabelParams(0, -1), 
    rapidcsv::SeparatorParams(
      ',', false, rapidcsv::sPlatformHasCR, false, true, '"'
    ), 
    rapidcsv::ConverterParams(true)
  );

  optionsMenu(userInput(), file);

  std::cout << "\nHASTA PRONTO!";

  return 0;
}
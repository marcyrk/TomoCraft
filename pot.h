#ifndef POT_H
#define POT_H


#include <mraa.h>
#include <mraa/aio.h>	


class Pot{

void init_Pot(mraa_aio_context capteur, int pin){

capteur= mraa_aio_init(pin); //pin entre 0 et 3
}

int Read_Pot(mraa_aio_context capteur){

return(mraa_aio_read(capteur));
}

};

#endif

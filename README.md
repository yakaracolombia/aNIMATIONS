Reproductor minimo de .gif para esp8266 (wemos d1 mini)

Basado inicialmente en el video de volos projects https://youtu.be/-h9Vm0Ow_Is
en su video encontraran instrucciones para convertir .gif en .h

incluye ejemplo y un gif de nintendo 64 en el proyecto (se actualizara con futuras animaciones)


Tenemos una limitacion en cuestion del tamaño de archivo que podremos subir al wemos d1 ya que este NO PUEDE ser mayor a 2MB

no importa el tamaño del .gif para definir su peso final al ser convertido, ya que la imagen se escribira en texto plano
dando un codigo de color HEX por cada pixel a renderizar asi que el tamaño final del archivo depende UNICAMENTE 
de las dimensiones en pixeles multiplicada por la cantidad de fotogramas que componen la imagen

ejemplo: 

en el proyecto inicial se incluye el n64ykr.h

dentro encontraremos las primeras lineas que indican los datos del gif convertido con la herramienta de Volos Projects incluida en este video https://youtu.be/-h9Vm0Ow_Is

int frames=40;                                  //cantidad de fotogramas
int animation_width=70;                         //altura en pixeles
int animation_height=70;                        //ancho en pixeles
const unsigned short PROGMEM n64ykr[][4900]=.   //peso de cada fotograma (pixeles de altura multiplicados por pixeles de ancho ej: 70x70 = 4900)

la manera que he utilizado para crear .gif y que el resultado NO SUPERE LAS 2MB es seguir las instrucciones del video de volos projects https://youtu.be/-h9Vm0Ow_Is

usar la pagina https://ezgif.com para recortar el .gif, luego dimensionarlo, dividirlo en imagenes y tomar solo una de estas imagenes y convertirla con el programa de volos
depende del peso de esa imagen, se multiplica por la cantidad de fotogramas y asi tendremos un aproximado del tamano final

si alguien puede crear una mejor herramienta no dude en hacerlo ya que la herramienta de volos projects tarda entre 2 y 4 horas
en crear un .h a partir de un gif de 70px por 70px de 40 fotogramas como las del ejemplo


Reproductor minimo de .gif para esp8266 (wemos d1 mini)

hace uso de la libreria https://github.com/Bodmer/TFT_eSPI y esta debe ser configurada correctamente para la pantalla a usar

Basado inicialmente en el video de volos projects https://youtu.be/-h9Vm0Ow_Is
en su video encontraran instrucciones para convertir .gif en .h

mi fork incluye ejemplo y un gif de nintendo 64 en el proyecto (se actualizara con futuras animaciones)


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
const unsigned short PROGMEM n64ykr[][4900]=.   //pixeles de cada fotograma (pixeles de altura multiplicados por pixeles de ancho ej: 70x70 = 4900)


si se intenta escribir un .h de mas de 2MB al wemos D1 se obtendra el siguiente error de compilacion
![error2mb](https://user-images.githubusercontent.com/22075544/133444391-43233e0b-8c29-4b2a-bfdf-4f0e14375723.png)

![error 2mb txt](https://user-images.githubusercontent.com/22075544/133444420-6d3af46d-4ed8-41f7-9182-740d2be619e1.png)

la manera que he utilizado para crear .gif y que el resultado NO SUPERE LAS 2MB es seguir las instrucciones del video de volos projects https://youtu.be/-h9Vm0Ow_Is

usar la pagina https://ezgif.com para recortar el .gif, luego dimensionarlo, dividirlo en imagenes y tomar solo una de estas imagenes y convertirla con el programa de volos
depende del peso de esa imagen, se multiplica por la cantidad de fotogramas y asi tendremos un aproximado del tamano final

si alguien puede crear una mejor herramienta no dude en hacerlo ya que la herramienta de volos projects tarda entre 2 y 4 horas
en crear un .h a partir de un gif de 70px por 70px de 40 fotogramas como las del ejemplo

los datos que podemos configurar para girar, ubicar y posicionar nuestro gif son los siguientes:

![wemos 1](https://user-images.githubusercontent.com/22075544/133444910-a7ce19af-8c3b-4174-924e-4dcf0554a9dd.png)

en mi ejemplo he usado dos tipos de pantallas de diferntes fabricantes pero que gracias a la libreria https://github.com/Bodmer/TFT_eSPI 
son reconocidas de la misma manera, es OBLIGATORIO configurar el User_Setup.h ubicado en la carpeta delibrerias de arduino

comunmente /DOCUMENTOS/ARDUINO/LIBRERIAS/TFT_eSPI/User_Setup.h

en mi fork podran encontrar mi User_Setup.h configurado y el mismo que use en mi video tutorial

los pines de instalacion son los siguientes y los he ubicado segun los dos tipos de pantalla que tengo para hacer pruebas

![WEMOS FULL 1](https://user-images.githubusercontent.com/22075544/133446622-8721413a-7022-4276-bb50-610a4b62e091.jpg)

se pueden soldar  varias pantallas en paralelo para que ambas muestren la misma animacion al mismo tiempo, no se pueden manejar animaciones independientes
con la potencia del ESP8266 se necsitaria un MCU mas potente como el ESP32

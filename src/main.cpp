#include <Geode/Geode.hpp>
#include <Geode/modify/MenuLayer.hpp>
#include <vector>
#include <string>

using namespace geode::prelude;

class $modify(MenuLayer) {
    bool init() {
        // Primero ejecutamos el código original del juego
        if (!MenuLayer::init()) return false;

        // 1. Lista de mensajes animadores
        std::vector<std::string> mensajes = {
            "¡Hoy es el día del Extreme Demon!",
            "¡Dale con todo, Dashy!",
            "¡Ese nivel no se va a pasar solo!",
            "¡Céntrate y lo lograrás!",
            "¡Eres una leyenda en potencia!",
            "¡No te rindas, el 98% es solo un número!",
            "¡A darle átomos!"
        };

        // 2. Elegir uno al azar
        // Usamos rand() para algo simple
        std::string fraseElegida = mensajes[rand() % mensajes.size()];

        // 3. Crear el texto visual (Label)
        // Usamos "goldFont.fnt" para que se vea como el juego original
        auto etiqueta = CCLabelBMFont::create(fraseElegida.c_str(), "goldFont.fnt");

        // 4. Posicionarlo
        auto tamañoPantalla = CCDirector::sharedDirector()->getWinSize();
        
        // Lo ponemos arriba en el centro (puedes ajustar los números)
        etiqueta->setPosition({ tamañoPantalla.width / 2, tamañoPantalla.height - 50 });
        etiqueta->setScale(0.6f); // Tamaño del texto (0.5 es la mitad)
        etiqueta->setID("mensaje-animador-label"); // ID para que Geode sepa qué es

        // 5. Añadirlo a la pantalla
        this->addChild(etiqueta);

        return true;
    }
};

#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>

ALLEGRO_DISPLAY* janela = NULL;

struct CIRCULO {
	float cx, cy, raio, traco;
	ALLEGRO_COLOR cor;
};

void desenharCirculo(CIRCULO c) {
	if (c.traco == 0) {
		al_draw_filled_circle(c.cx, c.cy, c.raio, c.cor);
	}
	else {
		al_draw_circle(c.cx, c.cy, c.raio, c.cor, c.traco);
	}
}

int main() {
	al_init(); //inicialização da biblioteca
	al_init_primitives_addon(); //inicialização da bibilioteca de primitivas

	int x1 = -20;

	janela = al_create_display(800, 600); //criação da janela

	ALLEGRO_COLOR amarelo = al_map_rgb(255, 255, 0);

	CIRCULO c1 = { 400, 300, 80, 5, al_map_rgb(255, 255, 0) };
	CIRCULO c2 = { 400, 300, 60, 5, al_map_rgb(0, 500, 0) };
	CIRCULO c3 = { 400, 300, 20, 5, al_map_rgb(110, 0, 100) };

	for (x1 = -20; x1 < 760; x1 += 1) {
		al_clear_to_color(al_map_rgb(255, 255, 255));
		al_clear_to_color(al_map_rgb(255, 255, 255)); // inserindo cores

		al_draw_circle(400, 300, 140, al_map_rgb(255, 0, 0), 5); //criando um círculo

		al_draw_circle(400, 300, 120, al_map_rgb(0, 255, 0), 5);

		al_draw_circle(400, 300, 100, al_map_rgb(0, 0, 100), 5);

		desenharCirculo(c1);
		c1.cx += 1;
		c1.cy += 1;

		desenharCirculo(c2);
		c2.cx += 1;
		c2.cy -= 1;

		al_draw_circle(400, 300, 40, al_map_rgb(500, 0, 0), 5);

		desenharCirculo(c3);
		c3.cx -= 1;
		c3.cy -= 1;

		al_draw_filled_circle(200, 200, 50, al_map_rgb(0, 0, 255)); // criando um círculo preenchido

		al_draw_rectangle(600, 80, 660, 140, al_map_rgb(0, 255, 0), 5); // criando um retângulo

		al_draw_filled_rectangle(x1, 400, x1 +40, 440, amarelo);

	al_flip_display(); //mostrar o buffer na janela
	al_rest(0.05);
	}


	al_rest(10); //pausa de 15 segundos
}
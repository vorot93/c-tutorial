#include <stdio.h>

struct Timage {
int width;								//ширина холста
int height;								//высота холста
int canvas[100][100];							//сам холст
};

struct Timage a;
struct Timage *pimg;

void draw_horizontal_line(struct Timage *p,int hline_y,int hline_length) {		//горизонтальная линия длиной в холст
	int x;								//счётчик

	for (x=0;x<hline_length;x++) {
		p->canvas[x][hline_y]=1;
	}
}

void draw_vertical_line(struct Timage *p,int vline_x,int vline_length) {			//вертикальная линия длиной в холст
	int y;								//счётчик

	for (y=0;y<vline_length;y++){
		p->canvas[vline_x][y]=1;
	}
}

void draw_grid(){
	int hpos;							//счётчик
	int ypos;							//счётчик

	int grid_height=50;
	int grid_width=50;

	int cell_height=5;
	int cell_width=5;

	for (ypos=0;ypos<grid_width;ypos++){
		if (ypos % (cell_width+1) == 0){
			draw_vertical_line(pimg,ypos, grid_height);
		}
	}

	for (hpos=0;hpos<grid_height;hpos++){
		if (hpos % (cell_height+1) == 0){			//+1 т.к. 1 пиксель между ячейками (граница)
			draw_horizontal_line(pimg,hpos, grid_width);
		}
	}
}

void show(struct Timage* p) {
	printf("P1\n##################################\n#\n# Создано следующее PBM-изображение:\n#\n##################################\n#\n# CREATED BY PBM GENERATOR 0.1\n# (c) Artem Vorotnikov <artem@vorotnikov.me>, 2014\n#\n##################################\n#\n");
	printf("%i %i \n", p->width, p->height);
	int x;
	int y;

	for (y=0;y<p->height;y++){
		for(x=0;x<p->width;x++){
			printf("%d ",p->canvas[x][y]);
		}
		printf("\n");
	}
}

void init(struct Timage *p,int w, int h) {
    p->width=w;
    p->height=h;
}

int main(){
    pimg = &a;
	init(pimg,10,10);

	draw_grid();
	show(pimg);

	return 0;
}

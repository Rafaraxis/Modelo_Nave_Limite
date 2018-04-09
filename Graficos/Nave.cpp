#include "stdafx.h"
#include "Nave.h"

Nave::Nave() {
	angulo = 0.0f;
	coordenadas = vec3(0.0f, 0.0f, 0.0f);
	transformaciones = mat4(1.0f);
}

void Nave::rotarNave(int direccion) {
	float rotacion = velocidadAngular;
	if (direccion == 1) {
		rotacion = -rotacion;
	}
	//transformaciones = 
		//rotate(transformaciones, rotacion, vec3(0.0f, 0.0f, 1.0f));

	angulo += rotacion;
	
}

void Nave::moverNave() {
	float anguloDesfasado = angulo + 90.0f;
	vec3 traslacion = vec3(cos(anguloDesfasado * 3.14159f / 180.0f) * velocidad,
		sin(anguloDesfasado * 3.14159f / 180.0f) * velocidad, 0.0f);

	//transformaciones =
		//translate(transformaciones, traslacion);

	coordenadas += traslacion;

	if (coordenadas.y > 1.1)
	{
		coordenadas.y -= 2.1;
	}
	else if (coordenadas.y < -1.1)
	{
		coordenadas.y += 2.1;
	}
	else if (coordenadas.x > 1.1)
	{
		coordenadas.x -= 2.1;
	}
	else if (coordenadas.x < -1.1)
	{
		coordenadas.x += 2.1;
	}
	cout << coordenadas.x << "," << coordenadas.y << endl;

	/*if (coordenadas.y >= 1.2) {
		coordenadas.y -= 2.2f;
		transformaciones =
			translate(transformaciones, vec3(0.0f,-2.2f,0.0f));
	}*/
}

void Nave::actualizarTransformaciones()
{
	//Reseteando transformaciones a una matriz identidad
	transformaciones = mat4(1.0f);
	transformaciones = translate(transformaciones, coordenadas);
	transformaciones = rotate(transformaciones, angulo * 3.14159f / 180.0f, vec3(0.0f, 0.0f, 1.0f));
}

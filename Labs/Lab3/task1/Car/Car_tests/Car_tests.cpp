#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "CCar.h"

TEST_CASE("Test CCar class instance creation")
{
	CCar car;

	/* Проверяем, что при создании машины её двигатель выключен, скорость равна 0, она не двигается и стоит на нейтральной передаче */
	CHECK(car.GetEngineState() == "Off");
	CHECK(car.GetSpeed() == 0);
	CHECK(car.GetDirection() == "Not moving");
	CHECK(car.GetGear() == 0);
}

TEST_CASE("Car engine starting test")
{
	CCar car;

	/* Включаем двигатель и проверяем, запустился ли он*/
	CHECK(car.TurnEngineOn());
	CHECK(car.GetEngineState() == "On");

	/* Проверяем, останется ли машина неподвижной, будет иметь нулевую скорость и стоять на нейтральной передаче после включения двигателя */
	CHECK(car.GetSpeed() == 0);
	CHECK(car.GetDirection() == "Not moving");
	CHECK(car.GetGear() == 0);

	/* Проверяем, можно ли включить двигатель у автомобиля, если он уже запущен (двигатель не должен запускаться снова) */
	CHECK(!car.TurnEngineOn());
}

TEST_CASE("Car speed setting test")
{
	CCar car;

	/* Проверяем, можно ли развить какую-либо скорость при выключенном двигателе (нельзя)*/
	CHECK(!car.SetSpeed(20));

	car.TurnEngineOn();

	/* Переключаем передачу на заднюю и проверяем, можно ли достигнуть скорости, находящиеся и не находящиеся в диапазоне передачи */
	car.SetGear(-1);
	CHECK(car.SetSpeed(20));
	CHECK(!car.SetSpeed(21));
	CHECK(car.SetSpeed(0));

	car.SetGear(0);

	/* Аналогично протестируем достижение скоростей на других передачах */
	car.SetGear(1);
	CHECK(car.SetSpeed(30));
	CHECK(!car.SetSpeed(31));

	car.SetGear(2);
	CHECK(!car.SetSpeed(19));
	CHECK(car.SetSpeed(50));
	CHECK(!car.SetSpeed(51));

	car.SetGear(3);
	CHECK(!car.SetSpeed(29));
	CHECK(car.SetSpeed(60));
	CHECK(!car.SetSpeed(61));

	car.SetGear(4);
	CHECK(!car.SetSpeed(39));
	CHECK(car.SetSpeed(90));
	CHECK(!car.SetSpeed(91));

	car.SetGear(5);
	CHECK(!car.SetSpeed(49));
	CHECK(car.SetSpeed(120));
	CHECK(!car.SetSpeed(151));

	/* Проверяем, можно ли развить скорость, находясь на нейтральной передаче (нельзя), или уменьшить скорость (можно) */
	car.SetGear(0);
	CHECK(!car.SetSpeed(150));
	CHECK(car.SetSpeed(100));
	CHECK(car.SetSpeed(0));
}

TEST_CASE("Car gear switching test")
{
	CCar car;

	/* Проверяем, можно ли переключиться на нейтральную передачу (можно) или на любую другую передачу (нельзя) при выключенном двигателе */
	CHECK(car.SetGear(0));
	CHECK(!car.SetGear(1));

	car.TurnEngineOn();

	/* Проверяем, можно ли переключиться на заднюю передачу */
	CHECK(car.SetGear(-1));
	car.SetSpeed(20);

	/* Проверяем, можно ли переключиться с задней передачи на первую при ненулевой скорости (нельзя) */
	CHECK(!car.SetGear(1));

	CHECK(car.SetGear(0));

	/* Проверяем, можно ли переключиться с нейтральной передачи на первую, если машина еще катится назад по инерции (нельзя) */
	CHECK(!car.SetGear(1));

	car.SetSpeed(0);

	/* Проверяем, можно ли переключиться на первую передачу */
	CHECK(car.SetGear(1));

	/* Проверяем, можно ли переключиться на заднюю передачу с первой при нулевой скорости */
	CHECK(car.SetGear(-1));

	/* Проверяем, можно ли переключиться на первую передачу с задней при нулевой скорости */
	CHECK(car.SetGear(1));

	/* Проверяем переключения передач на возможных и невозможных для этого скоростях */
	CHECK(!car.SetGear(2));
	CHECK(car.SetSpeed(25));
	CHECK(car.SetGear(2));

	/* Проверяем, можно ли переключить передачу на нейтральную*/
	CHECK(car.SetGear(0));

	/* Устанавливаем прежнюю передачу и проверяем, не изменилась ли скорость */
	car.SetGear(2);
	CHECK(car.GetSpeed() == 25);

	car.SetSpeed(35);
	CHECK(car.SetGear(3));
	CHECK(!car.SetGear(1));
	CHECK(!car.SetGear(4));

	car.SetSpeed(55);
	CHECK(car.SetGear(4));
	CHECK(!car.SetGear(2));

	car.SetSpeed(90);
	CHECK(car.SetGear(5));
	CHECK(!car.SetGear(3));

	/* Проверяем, можно ли включить передачу, больше чем пятую (нельзя) */
	CHECK(!car.SetGear(6));
}

TEST_CASE("Car engine stoping test")
{
	CCar car;

	/* Проверяем, можно ли выключить двигатель, если он не был включенным (нельзя) */
	CHECK(!car.TurnEngineOff());

	car.TurnEngineOn();

	/* Проверяем, можно ли выключить двигатель, если он был включенным */
	CHECK(car.TurnEngineOff());
	CHECK(car.GetEngineState() == "Off");

	/* Проверяем, что другие свойства машины не изменились от начальных */
	CHECK(car.GetSpeed() == 0);
	CHECK(car.GetDirection() == "Not moving");
	CHECK(car.GetGear() == 0);

	/* Проверяем, можно ли выключить двигатель при ненулевой скорости и не на нейтральной передаче (нельзя) */
	car.TurnEngineOn();
	car.SetGear(1);
	car.SetSpeed(25);
	CHECK(!car.TurnEngineOff());
}
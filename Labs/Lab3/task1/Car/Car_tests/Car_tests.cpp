#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "CCar.h"

TEST_CASE("Test CCar class instance creation")
{
	CCar car;

	/* ���������, ��� ��� �������� ������ � ��������� ��������, �������� ����� 0, ��� �� ��������� � ����� �� ����������� �������� */
	CHECK(car.GetEngineState() == "Off");
	CHECK(car.GetSpeed() == 0);
	CHECK(car.GetDirection() == "Not moving");
	CHECK(car.GetGear() == 0);
}

TEST_CASE("Car engine starting test")
{
	CCar car;

	/* �������� ��������� � ���������, ���������� �� ��*/
	CHECK(car.TurnEngineOn());
	CHECK(car.GetEngineState() == "On");

	/* ���������, ��������� �� ������ �����������, ����� ����� ������� �������� � ������ �� ����������� �������� ����� ��������� ��������� */
	CHECK(car.GetSpeed() == 0);
	CHECK(car.GetDirection() == "Not moving");
	CHECK(car.GetGear() == 0);

	/* ���������, ����� �� �������� ��������� � ����������, ���� �� ��� ������� (��������� �� ������ ����������� �����) */
	CHECK(!car.TurnEngineOn());
}

TEST_CASE("Car speed setting test")
{
	CCar car;

	/* ���������, ����� �� ������� �����-���� �������� ��� ����������� ��������� (������)*/
	CHECK(!car.SetSpeed(20));

	car.TurnEngineOn();

	/* ����������� �������� �� ������ � ���������, ����� �� ���������� ��������, ����������� � �� ����������� � ��������� �������� */
	car.SetGear(-1);
	CHECK(car.SetSpeed(20));
	CHECK(!car.SetSpeed(21));
	CHECK(car.SetSpeed(0));

	car.SetGear(0);

	/* ���������� ������������ ���������� ��������� �� ������ ��������� */
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

	/* ���������, ����� �� ������� ��������, �������� �� ����������� �������� (������), ��� ��������� �������� (�����) */
	car.SetGear(0);
	CHECK(!car.SetSpeed(150));
	CHECK(car.SetSpeed(100));
	CHECK(car.SetSpeed(0));
}

TEST_CASE("Car gear switching test")
{
	CCar car;

	/* ���������, ����� �� ������������� �� ����������� �������� (�����) ��� �� ����� ������ �������� (������) ��� ����������� ��������� */
	CHECK(car.SetGear(0));
	CHECK(!car.SetGear(1));

	car.TurnEngineOn();

	/* ���������, ����� �� ������������� �� ������ �������� */
	CHECK(car.SetGear(-1));
	car.SetSpeed(20);

	/* ���������, ����� �� ������������� � ������ �������� �� ������ ��� ��������� �������� (������) */
	CHECK(!car.SetGear(1));

	CHECK(car.SetGear(0));

	/* ���������, ����� �� ������������� � ����������� �������� �� ������, ���� ������ ��� ������� ����� �� ������� (������) */
	CHECK(!car.SetGear(1));

	car.SetSpeed(0);

	/* ���������, ����� �� ������������� �� ������ �������� */
	CHECK(car.SetGear(1));

	/* ���������, ����� �� ������������� �� ������ �������� � ������ ��� ������� �������� */
	CHECK(car.SetGear(-1));

	/* ���������, ����� �� ������������� �� ������ �������� � ������ ��� ������� �������� */
	CHECK(car.SetGear(1));

	/* ��������� ������������ ������� �� ��������� � ����������� ��� ����� ��������� */
	CHECK(!car.SetGear(2));
	CHECK(car.SetSpeed(25));
	CHECK(car.SetGear(2));

	/* ���������, ����� �� ����������� �������� �� �����������*/
	CHECK(car.SetGear(0));

	/* ������������� ������� �������� � ���������, �� ���������� �� �������� */
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

	/* ���������, ����� �� �������� ��������, ������ ��� ����� (������) */
	CHECK(!car.SetGear(6));
}

TEST_CASE("Car engine stoping test")
{
	CCar car;

	/* ���������, ����� �� ��������� ���������, ���� �� �� ��� ���������� (������) */
	CHECK(!car.TurnEngineOff());

	car.TurnEngineOn();

	/* ���������, ����� �� ��������� ���������, ���� �� ��� ���������� */
	CHECK(car.TurnEngineOff());
	CHECK(car.GetEngineState() == "Off");

	/* ���������, ��� ������ �������� ������ �� ���������� �� ��������� */
	CHECK(car.GetSpeed() == 0);
	CHECK(car.GetDirection() == "Not moving");
	CHECK(car.GetGear() == 0);

	/* ���������, ����� �� ��������� ��������� ��� ��������� �������� � �� �� ����������� �������� (������) */
	car.TurnEngineOn();
	car.SetGear(1);
	car.SetSpeed(25);
	CHECK(!car.TurnEngineOff());
}
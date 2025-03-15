#include "graphics.h"
#include "Browser.h"

// ��������� ����������
void update(float ms)
{
    // ������������ ������ ���� ��������� (Browser)
    Browser* bro = reinterpret_cast<Browser*>(graphics::getUserData());
    bro->update(); // ������������ ��� ���������
}

// ��������� ���������
void draw()
{
    // ������������ ������ ���� ��������� (Browser)
    Browser* bro = reinterpret_cast<Browser*>(graphics::getUserData());
    bro->draw(); // ����������� ��� ���������
}

int main()
{
    // ������������ ���� ��� ���������
    Browser browser;

    // ������������ �� �������� ��� �������� �������������
    graphics::createWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Movies");

    // �������� �� �������� ��� ������ (��� �������� ��� ���������)
    graphics::setUserData(&browser);

    // �������� �� ��������� ���������
    graphics::setDrawFunction(draw);

    // �������� �� ��������� ����������
    graphics::setUpdateFunction(update);

    // �������� �� ������� ��� �����
    graphics::setCanvasSize(CANVAS_WIDTH, CANVAS_HEIGHT);

    // �������� �� ���������� �������� ��� �����
    graphics::setCanvasScaleMode(graphics::CANVAS_SCALE_FIT);

    // ������������� ��� ���������
    browser.init();

    // �������� ��� ����� ��������� ��� �������� �������������
    graphics::startMessageLoop();

    return 0;
}

#include "DHGameObject2p.h"


namespace dh {
    GameObject2p::GameObject2p()
        : mX(0)
        , mY(0)
    {}

    GameObject2p::~GameObject2p() {

    }

    void GameObject2p::Update() {


        if (GetAsyncKeyState('A') & 0X8000) {
            mX -= 500*Time::DeltaTime();
        }
        if (GetAsyncKeyState('D') & 0X8000) {
            mX += 500 * Time::DeltaTime();
        }
        if (GetAsyncKeyState('W') & 0X8000) {
            mY -= 500 * Time::DeltaTime();
        }
        if (GetAsyncKeyState('S') & 0X8000) {
            mY += 500 * Time::DeltaTime();
        }
        
        if (mX > 1500) mX = 1500;
        if (mX < 0) mX = 0;
        if (mY > 700) mY = 700;
        if (mY < 0) mY = 0;

    }

    void GameObject2p::LateUpdate() {


    }
    void GameObject2p::Render(HDC hdc) {

        //�Ķ� �귯�� ����
        HBRUSH RedBrush = CreateSolidBrush(RGB(255,0,0));

        //�Ķ� �귯�� DC�� ����, ��� �귯�� ����
        HBRUSH oldBrush = (HBRUSH)SelectObject(hdc, RedBrush);

        //Rectangle(mHdc, 100, 100, 200, 200);

        ////��� ���� �귯���� ����
        //SelectObject(mHdc, oldBrush);
        ////�Ķ� �귯�� ����
        //DeleteObject(BlueBrush);

        HPEN BluePen = CreatePen(PS_DOT, 2, RGB(0, 0, 255));
        HPEN oldPen = (HPEN)SelectObject(hdc, BluePen);

        /*Ellipse(mHdc, 200, 200, 300, 300);*/

        SelectObject(hdc, oldPen);


        /* HBRUSH grayBrush = (HBRUSH)GetStockObject(GRAY_BRUSH);
         oldBrush = (HBRUSH)SelectObject(mHdc, grayBrush);*/



         // �⺻���� ���� ��� �Ǵ� GDI ������Ʈ�� �̸� DC �ȿ� ����� �ξ��µ�, 
         // �� ������Ʈ���� ���� ������Ʈ��� �Ѵ�.

         //Rectangle(mHdc, 100 + mX, 100 + mY, 200 + mX, 200 + mY);


        Ellipse(hdc, mX, mY, mX+100, mY+100);

        SelectObject(hdc, oldBrush);
        /*DeleteObject(grayBrush);*/



        DeleteObject(RedBrush);
        DeleteObject(BluePen);

    }
}
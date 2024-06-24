#include "DHGameObject.h"


namespace dh {
    GameObject::GameObject() {


    }

    GameObject::~GameObject() {


    }

    void GameObject::Update() {
        
        
        if (GetAsyncKeyState(VK_LEFT) & 0X8000) {
            mX -= 0.01f;
        }
        if (GetAsyncKeyState(VK_RIGHT) & 0X8000) {
            mX += 0.01f;
        }
        if (GetAsyncKeyState(VK_UP) & 0X8000) {
            mY -= 0.01f;
        }
        if (GetAsyncKeyState(VK_DOWN) & 0X8000) {
            mY += 0.01f;
        }

    }
    
    void GameObject::LateUpdate() {


    }
    void GameObject::Render(HDC hdc) {

        //�Ķ� �귯�� ����
        HBRUSH BlueBrush = CreateSolidBrush(RGB(0, 0, 255));

        //�Ķ� �귯�� DC�� ����, ��� �귯�� ����
        HBRUSH oldBrush = (HBRUSH)SelectObject(hdc, BlueBrush);

        //Rectangle(mHdc, 100, 100, 200, 200);

        ////��� ���� �귯���� ����
        //SelectObject(mHdc, oldBrush);
        ////�Ķ� �귯�� ����
        //DeleteObject(BlueBrush);

        HPEN redPen = CreatePen(PS_DOT, 2, RGB(255, 0, 0));
        HPEN oldPen = (HPEN)SelectObject(hdc, redPen);

        /*Ellipse(mHdc, 200, 200, 300, 300);*/

        SelectObject(hdc, oldPen);


        /* HBRUSH grayBrush = (HBRUSH)GetStockObject(GRAY_BRUSH);
         oldBrush = (HBRUSH)SelectObject(mHdc, grayBrush);*/



         // �⺻���� ���� ��� �Ǵ� GDI ������Ʈ�� �̸� DC �ȿ� ����� �ξ��µ�, 
         // �� ������Ʈ���� ���� ������Ʈ��� �Ѵ�.

         //Rectangle(mHdc, 100 + mX, 100 + mY, 200 + mX, 200 + mY);

        
        Rectangle(hdc, 100 + mX, 200 + mY, 200 + mX, 300 + mY);

        SelectObject(hdc, oldBrush);
        /*DeleteObject(grayBrush);*/



        DeleteObject(BlueBrush);
        DeleteObject(redPen);

    }
}
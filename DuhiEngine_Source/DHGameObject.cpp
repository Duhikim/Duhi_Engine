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

        //파랑 브러쉬 생성
        HBRUSH BlueBrush = CreateSolidBrush(RGB(0, 0, 255));

        //파랑 브러쉬 DC에 선택, 흰색 브러쉬 리턴
        HBRUSH oldBrush = (HBRUSH)SelectObject(hdc, BlueBrush);

        //Rectangle(mHdc, 100, 100, 200, 200);

        ////흰색 원본 브러쉬로 선택
        //SelectObject(mHdc, oldBrush);
        ////파란 브러쉬 삭제
        //DeleteObject(BlueBrush);

        HPEN redPen = CreatePen(PS_DOT, 2, RGB(255, 0, 0));
        HPEN oldPen = (HPEN)SelectObject(hdc, redPen);

        /*Ellipse(mHdc, 200, 200, 300, 300);*/

        SelectObject(hdc, oldPen);


        /* HBRUSH grayBrush = (HBRUSH)GetStockObject(GRAY_BRUSH);
         oldBrush = (HBRUSH)SelectObject(mHdc, grayBrush);*/



         // 기본으로 자주 사용 되는 GDI 오브젝트를 미리 DC 안에 만들어 두었는데, 
         // 그 오브젝트들을 스톡 오브젝트라고 한다.

         //Rectangle(mHdc, 100 + mX, 100 + mY, 200 + mX, 200 + mY);

        
        Rectangle(hdc, 100 + mX, 200 + mY, 200 + mX, 300 + mY);

        SelectObject(hdc, oldBrush);
        /*DeleteObject(grayBrush);*/



        DeleteObject(BlueBrush);
        DeleteObject(redPen);

    }
}
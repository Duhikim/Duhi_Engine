#include "DHGameObject2p.h"


namespace dh {
    GameObject2p::GameObject2p() {


    }

    GameObject2p::~GameObject2p() {


    }

    void GameObject2p::Update() {


        if (GetAsyncKeyState('A') & 0X8000) {
            mX -= 0.01f;
        }
        if (GetAsyncKeyState('D') & 0X8000) {
            mX += 0.01f;
        }
        if (GetAsyncKeyState('W') & 0X8000) {
            mY -= 0.01f;
        }
        if (GetAsyncKeyState('S') & 0X8000) {
            mY += 0.01f;
        }

    }

    void GameObject2p::LateUpdate() {


    }
    void GameObject2p::Render(HDC hdc) {

        //파랑 브러쉬 생성
        HBRUSH RedBrush = CreateSolidBrush(RGB(255, 0, 0));

        //파랑 브러쉬 DC에 선택, 흰색 브러쉬 리턴
        HBRUSH oldBrush = (HBRUSH)SelectObject(hdc, RedBrush);

        //Rectangle(mHdc, 100, 100, 200, 200);

        ////흰색 원본 브러쉬로 선택
        //SelectObject(mHdc, oldBrush);
        ////파란 브러쉬 삭제
        //DeleteObject(BlueBrush);

        HPEN BluePen = CreatePen(PS_DOT, 2, RGB(0, 0, 255));
        HPEN oldPen = (HPEN)SelectObject(hdc, BluePen);

        /*Ellipse(mHdc, 200, 200, 300, 300);*/

        SelectObject(hdc, oldPen);


        /* HBRUSH grayBrush = (HBRUSH)GetStockObject(GRAY_BRUSH);
         oldBrush = (HBRUSH)SelectObject(mHdc, grayBrush);*/



         // 기본으로 자주 사용 되는 GDI 오브젝트를 미리 DC 안에 만들어 두었는데, 
         // 그 오브젝트들을 스톡 오브젝트라고 한다.

         //Rectangle(mHdc, 100 + mX, 100 + mY, 200 + mX, 200 + mY);


        Ellipse(hdc, 500 + mX, 700 + mY, 600 + mX, 800 + mY);

        SelectObject(hdc, oldBrush);
        /*DeleteObject(grayBrush);*/



        DeleteObject(RedBrush);
        DeleteObject(BluePen);

    }
}
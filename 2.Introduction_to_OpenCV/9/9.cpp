﻿// 9.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <opencv2/opencv.hpp>

int main(){
    cv::VideoCapture cap;
    cv::VideoWriter writer;
    cap.open(0);
    double fps = cap.get(cv::CAP_PROP_FPS);
    cv::Size size(cap.get(cv::CAP_PROP_FRAME_WIDTH)/2, cap.get(cv::CAP_PROP_FRAME_HEIGHT)/2);
    writer.open("Out.MJPG", cv::VideoWriter::fourcc('M', 'J', 'P', 'G'), fps, size);
    cv::Mat img1, img2;
    cv::namedWindow("Task1", cv::WINDOW_AUTOSIZE);
    for (;;) {
        cap >> img1;
        cv::pyrDown(img1, img2);
        writer << img2;
        cv::imshow("Task1", img2);
        char c = cv::waitKey(10);
        if (c == 27)
            break;
    }
    cap.release();
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.

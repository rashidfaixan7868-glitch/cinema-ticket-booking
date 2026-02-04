#include <iostream>
using namespace std;

const int row = 5;
const int column = 7;

int seats[row][column] = {0};

void viewSeatLayout()
{
    cout << "---- Seats Layout( 0 = available , 1 = Booked)----" << endl;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            cout << seats[i][j] << " ";
        }
        cout << "\n";
    }
}
void bookSingleSeat()
{
    cout << "Enter row and column to Book :";
    int r, c;
    cin >> r >> c;
    if (r >= 0 && r < row && c >= 0 && c < column && seats[r][c] == 0)
    {
        seats[r][c] = 1;
        cout << "Seat Booked Successfully." << endl;
    }
    else
    {
        cout << "Invalid or Seat already Booked." << endl;
    }
}
void bookMultipleSeat()
{
    cout << "Enter Row , Starting Column and Number of Seats : ";
    int r, startingc, n;
    cin >> r >> startingc >> n;
    if (r >= 0 && r < row && startingc >= 0 && startingc < column && startingc + n <= column)
    {
        bool canbook = true;
        for (int i = 0; i < n; i++)
        {
            if (seats[r][startingc + i] == 1)
            {
                canbook = false;
                break;
            }
        }
        if (canbook)
        {

            for (int i = 0; i < n; i++)
            {
                seats[r][startingc + i] = 1;
            }
            cout << "Seats Booked Successfully." << endl;
        }
        else
        {
            cout << "One or more seats are already booked.\n";
        }
    }
    else
    {
        cout << "Invalid or Seats already booked." << endl;
    }
}

void cancelSeatBooking()
{
    cout << "Enter row and coulumn to cancel : ";
    int r, c;
    cin >> r >> c;
    if (r >= 0 && r < row && c >= 0 && c < column && seats[r][c] == 1)
    {
        seats[r][c] = 0;
        cout << "Booking Cancel Succesfully. " << endl;
    }
    else
    {
        cout << "invalid seat or not booked.\n";
    }
}
void availableSeatOnly()
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            if (seats[i][j] == 0)
            {
                cout << "row : " << i << "   coulumn : " << j << endl;
            }
        }
    }
}
int main()
{

    int choice;
    while (true)
    {

        cout << "====== Cinema Ticket Booking ====== " << endl;
        cout << " 1. View Seat Layout" << endl;
        cout << " 2. Book a Single Seat" << endl;
        cout << " 3. Book a block of seat" << endl;
        cout << " 4. Cancel a seat booking" << endl;
        cout << " 5. Display available seats only" << endl;
        cout << " 6. Exit" << endl;
        cout << "Enter your choice (1 to 6) to select a function : ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            viewSeatLayout();
            break;
        case 2:
            bookSingleSeat();
            break;
        case 3:
            bookMultipleSeat();
            break;
        case 4:
            cancelSeatBooking();
            break;
        case 5:
            availableSeatOnly();
            break;

        case 6:
            cout << "Exiting system. Thank you!.\n";
            return 0;

        default:
            cout << "invalid choice . Please Try Again.\n";
            break;
        }
    }

    return 0;
}
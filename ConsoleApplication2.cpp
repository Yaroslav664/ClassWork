#include <iostream>

using namespace std;

class Image {
private:
	unsigned short int width;
	unsigned short int height;
	string name;
	string extension;
	unsigned short int imageWeightInByte;

public:
	string format;
	string comment;
	string tags[100];
	unsigned short int rating;

	Image(unsigned short int inputWidth = 1000, unsigned short int inputHeight = 1000) {
		width = inputWidth;
		height = inputHeight;
		format = "";
		comment = "";
		tags;
		extension = ".jpg";
		name = "Image_01" + extension;
		rating = 0;
		imageWeightInByte = width * height * 3;
	}
	//GET
	unsigned short int getWidth() { return width; }
	unsigned short int getImageWeightInByte() { return imageWeightInByte; }
	string getName() { return name; }
	//SET
	void setWidth(unsigned short int inputWidth) { if (inputWidth > 500 && inputWidth < 10000) { width = inputWidth; } }
	void setExtension(string newExtension) {
		if (newExtension == ".jpg" || newExtension == ".png" || newExtension == ".tiff") {
			extension = newExtension;
		}
		else {
			cout << "error" << endl;
		}
	}
	void setName(string inputname) {
		bool hasDigits = false;
		for (char c : inputname) {
			if (isdigit(c)) {
				hasDigits = true;
				break;
			}
		} if (hasDigits == true) {
			name = inputname;  
		} 
	}

};

int main()
{
	Image first{ 640, 1280 };
	cout << first.getName();
}
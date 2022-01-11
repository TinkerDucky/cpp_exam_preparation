#include "Canvas.h"

Canvas::Canvas(unsigned int width, unsigned int height, unsigned int init_color)
    : properties({{"width", width}, {"height", height}}) {
  this->pixels = new unsigned int*[this->properties.at("width")];
  for (unsigned int i = 0; i < this->properties.at("width"); i++) {
    this->pixels[i] = new unsigned int[this->properties.at("height")];
    for (unsigned int j = 0; j < this->properties.at("height"); j++) {
      this->pixels[i][j] = init_color;
    }
  }

  cout << "Canvas Constructor" << endl;
}

Canvas::~Canvas() {
  if (this->pixels == nullptr && this->properties.size() == 0) return;

  for (unsigned int i = 0; i < this->properties.at("height"); i++) {
    delete[] this->pixels[i];
  }

  delete[] this->pixels;

  cout << "Canvas Destructor" << endl;
}

Canvas::Canvas(const Canvas& obj) : properties(obj.properties) {
  this->pixels = new unsigned int*[obj.properties.at("width")];
  for (unsigned int i = 0; i < obj.properties.at("width"); i++) {
    this->pixels[i] = new unsigned int[obj.properties.at("height")];
    for (unsigned int j = 0; j < obj.properties.at("height"); j++) {
      this->pixels[i][j] = obj.pixels[i][j];
    }
  }

    cout << "Canvas Copy Constructor" << endl;
}

Canvas::Canvas(Canvas&& obj) noexcept
    : properties(obj.properties), pixels(obj.pixels) {
  obj.pixels = nullptr;
  obj.properties = map<string, unsigned int>();

  cout << "Canvas Move Constructor" << endl;
}

Canvas& Canvas::operator=(Canvas obj) {
  swap(obj);

  cout << "Canvas Copy Assignment Operator" << endl;

  return *this;
}

//Canvas Canvas::operator=(Canvas&& obj) noexcept { 
//    swap(obj); 
//}

bool Canvas::operator()(const Canvas& c) {
  return (this->properties.at("width") * this->properties.at("height")) < (c.properties.at("width") * c.properties.at("height"));
}

void Canvas::setPixelColor(unsigned int x, unsigned int y, unsigned int color) {
  if (x < this->properties.at("width") && y < this->properties.at("height")) {
    this->pixels[x][y] = color;
  }
}

unsigned int Canvas::getPixelColor(unsigned int x, unsigned int y) {
  if (x < this->properties.at("width") && y < this->properties.at("height")) {
    return this->pixels[x][y];
  }

  return 0;
}

void Canvas::invert() {
  for (unsigned int i = 0; i < this->properties.at("width"); i++) {
    for (unsigned int j = 0; j < this->properties.at("height"); j++) {
      unsigned int color = this->pixels[i][j];
      unsigned int red_part = (color & 0x00ff0000) >> 16;
      unsigned int blue_part = (color & 0x0000ff00) >> 8;
      unsigned int green_part = color & 0x000000ff;

      red_part = 0xff - red_part;
      blue_part = 0xff - blue_part;
      green_part = 0xff - green_part;

      this->pixels[i][j] =
          0xff000000 | (red_part << 16) | (blue_part << 8) | green_part;
    }
  }
}

void Canvas::print() {
  string text("");

  for (unsigned int i = 0; i < this->properties.at("height"); i++) {
    for (unsigned int j = 0; j < this->properties.at("width"); j++) {
      unsigned int color = this->pixels[j][i];
      unsigned int red_part = (color & 0x00ff0000) >> 16;
      unsigned int blue_part = (color & 0x0000ff00) >> 8;
      unsigned int green_part = color & 0x000000ff;

      text += "\033[38;2;" + std::to_string(red_part) + ";" +
              std::to_string(blue_part) + ";" + std::to_string(green_part) +
              "mo \033[0m";
    }
    text += "\n";
  }

  cout << text << endl;
}

void Canvas::swap(Canvas& c) {
    using std::swap;

    swap(this->pixels, c.pixels);
    swap(this->properties, c.properties);
}

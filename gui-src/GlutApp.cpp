#include "GlutApp.h"
#include "glut_app.h"
#include "image_menu.h"

GlutApp::GlutApp(int height, int width)
: mHeight(height), mWidth(width), mActionData(mInputStream, mOutputStream), mMinX(-2.0), mMaxX(2.0), mMinY(-2.0), mMaxY(2.0), mA(-0.7269), mB(0.1889), mInteractionMode(IM_FRACTAL), mFractalMode(M_MANDELBROT), mMaxNumber(200), /*pink*/mColor1(235, 4, 80), /*blue*/mColor2(0, 0, 139), /*green*/mColor3(57, 255, 20), mNumColor(32), mHSVColor(false) {
      configureMenu(mMenuData);
      mActionData.setGrid(new ComplexFractal);
      setColorTable();
      createFractal();
}

void GlutApp::setSize(int height, int width) {
  mHeight = height;
  mWidth = width;
}
int GlutApp::getHeight() const {
  return mHeight;
}
int GlutApp::getWidth() const {
  return mWidth;
}
void GlutApp::display() {
    if ( mInteractionMode == IM_FRACTAL ) {
        PPM& p = mActionData.getOutputImage();
        double max = static_cast<double>(p.getMaxColorValue());
        double r, g, b;
        int row, column;
        glBegin( GL_POINTS );
        for(row = 0; row < p.getHeight(); row++) {
            for(column = 0; column < p.getWidth(); column++) {
                r = p.getChannel(row, column, 0) / max;
                g = p.getChannel(row, column, 1) / max;
                b = p.getChannel(row, column, 2) / max;
                glColor3d(r, g, b);
                glVertex2i(column, p.getHeight()-row-1);
            }
        }
        //DrawText(10,10, "Hello");
        glEnd( );
    }
    else  {
        displayColorTable();
    }/*
    else if ( mInteractionMode == IM_COLOR2 ) {
        displayColorTable();
    }
    else if ( mInteractionMode == IM_COLOR3 ) {
        displayColorTable();
    }*/
}
void GlutApp::createJulia() {

  // julia
    mOutputStream.clear();
    mOutputStream.str("");
    mInputStream.clear();
    mInputStream.str("");
  takeAction("julia", mMenuData, mActionData);
  
  // grid
    mOutputStream.clear();
    mOutputStream.str("");
    mInputStream.clear();
    mInputStream.str("");
  {
    std::stringstream tmp;
    tmp << mHeight << " " << mWidth << " " << 200;
    mInputStream.str(tmp.str());
  }
  takeAction("grid", mMenuData, mActionData);

  // julia-parameters
    mOutputStream.clear();
    mOutputStream.str("");
    mInputStream.clear();
    mInputStream.str("");
  {
    std::stringstream tmp;
    tmp << 0.45 << " " << -0.32;
    mInputStream.str(tmp.str());
  }
  takeAction("julia-parameters", mMenuData, mActionData);

  // fractal-plane-size
    mOutputStream.clear();
    mOutputStream.str("");
    mInputStream.clear();
    mInputStream.str("");
  {
    std::stringstream tmp;
    tmp << -2.0 << " " << 2.0 << " "<< -2.0 << " " << 2.0;
    mInputStream.str(tmp.str());
  }
  takeAction("fractal-plane-size", mMenuData, mActionData);

  
  // fractal-calculate
    mOutputStream.clear();
    mOutputStream.str("");
    mInputStream.clear();
    mInputStream.str("");
  takeAction("fractal-calculate", mMenuData, mActionData);

  // grid-apply-color-table
    mOutputStream.clear();
    mOutputStream.str("");
    mInputStream.clear();
    mInputStream.str("");
  takeAction("grid-apply-color-table", mMenuData, mActionData);

}

void GlutApp::selectJulia() {
    mOutputStream.clear();
    mInputStream.clear();
    mInputStream.str("");
    takeAction("julia", mMenuData, mActionData);
    createJulia();
}

void GlutApp::selectMandelbrot() {
    mOutputStream.clear();
    mInputStream.clear();
    mInputStream.str("");
    takeAction("mandelbrot", mMenuData, mActionData);
}

void GlutApp::selectComplexFractal() {
    mOutputStream.clear();
    mInputStream.clear();
    mInputStream.str("");
    takeAction("complex-fractal", mMenuData, mActionData);
}

void GlutApp::configureGrid(int max) {
    mOutputStream.clear();
    mInputStream.clear();
    mInputStream.str("");
    
    //

    //mActionData.getGrid().setGridSize( mHeight, mWidth );
    //mActionData.getGrid().setMaxNumber( max );
    //
    {
      std::stringstream tmp;
      tmp << mHeight << " " << mWidth << " " << max;
      mInputStream.str(tmp.str());
    }
    
    takeAction("grid", mMenuData, mActionData);

}
void GlutApp::juliaParameters(double a, double b) {
    (void)a;
    (void)b;
    mOutputStream.clear();
    mInputStream.clear();
    mInputStream.str("");
    {
      std::stringstream tmp;
      tmp << a << " " << b;
      mInputStream.str(tmp.str());
    }
    //mA = a;
    //mB = b;
    takeAction("julia-parameters", mMenuData, mActionData);
}

void GlutApp::fractalPlaneSize(double x_min, double x_max, double y_min, double y_max) {
    (void)x_min;
    (void)x_max;
    (void)y_min;
    (void)y_max;
    mOutputStream.clear();
    mInputStream.clear();
    mInputStream.str("");
    {
      std::stringstream tmp;
      tmp << x_min << " " << x_max << " " << y_min << " " << y_max;
      mInputStream.str(tmp.str());
    }
    takeAction("fractal-plane-size", mMenuData, mActionData);
}

void GlutApp::fractalCalculate() {
    mOutputStream.clear();
    mInputStream.clear();
    mInputStream.str("");
    takeAction("fractal-calculate", mMenuData, mActionData);
}

void GlutApp::gridApplyColorTable() {
    mOutputStream.clear();
    mInputStream.clear();
    mInputStream.str("");
    takeAction("grid-apply-color-table", mMenuData, mActionData);
}

void GlutApp::createJulia2() {
    // julia
    mOutputStream.clear();
    mInputStream.clear();
    mInputStream.str("");
    takeAction("julia", mMenuData, mActionData);
    
    // grid
    mOutputStream.clear();
    mInputStream.clear();
    {
      std::stringstream tmp;
      tmp << mHeight << " " << mWidth << " " << 200;
      mInputStream.str(tmp.str());
    }
    takeAction("grid", mMenuData, mActionData);

    // julia-parameters
    mOutputStream.clear();
    mInputStream.clear();
    {
      std::stringstream tmp;
      tmp << 0.4 << " " << 0.6;
      mInputStream.str(tmp.str());
    }
    takeAction("julia-parameters", mMenuData, mActionData);

    // fractal-plane-size
    mOutputStream.clear();
    mInputStream.clear();
    {
      std::stringstream tmp;
      tmp << -0.5 << " " << 0.5 << " "<< -0.5 << " " << 0.5;
      mInputStream.str(tmp.str());
    }
    takeAction("fractal-plane-size", mMenuData, mActionData);

    
    // fractal-calculate
    mOutputStream.clear();
    mInputStream.clear();
    mInputStream.str("");
    takeAction("fractal-calculate", mMenuData, mActionData);

    // grid-apply-color-table
    mOutputStream.clear();
    mInputStream.clear();
    mInputStream.str("");
    takeAction("grid-apply-color-table", mMenuData, mActionData);

}

void GlutApp::createMandelbrot() {
    // mandelbrot
    mOutputStream.clear();
    mInputStream.clear();
    mInputStream.str("");
    takeAction("mandelbrot", mMenuData, mActionData);
    
    // grid
    mOutputStream.clear();
    mInputStream.clear();
    {
      std::stringstream tmp;
      tmp << mHeight << " " << mWidth << " " << 200;
      mInputStream.str(tmp.str());
    }
    takeAction("grid", mMenuData, mActionData);
    // fractal-plane-size
    mOutputStream.clear();
    mInputStream.clear();
    {
      std::stringstream tmp;
      tmp << -2.0 << " " << 2.0 << " "<< -2.0 << " " << 2.0;
      mInputStream.str(tmp.str());
    }
    takeAction("fractal-plane-size", mMenuData, mActionData);
    // fractal-calculate
    mOutputStream.clear();
    mInputStream.clear();
    mInputStream.str("");
    takeAction("fractal-calculate", mMenuData, mActionData);

    // grid-apply-color-table
    mOutputStream.clear();
    mInputStream.clear();
    mInputStream.str("");
    takeAction("grid-apply-color-table", mMenuData, mActionData);
}

void GlutApp::createMandelbrot2() {
    // mandelbrot
    mOutputStream.clear();
    mInputStream.clear();
    mInputStream.str("");
    takeAction("mandelbrot", mMenuData, mActionData);
    
    // grid
    mOutputStream.clear();
    mInputStream.clear();
    {
      std::stringstream tmp;
      tmp << mHeight << " " << mWidth << " " << 50;
      mInputStream.str(tmp.str());
    }
    takeAction("grid", mMenuData, mActionData);


    // fractal-plane-size
    mOutputStream.clear();
    mInputStream.clear();
    {
      std::stringstream tmp;
      tmp << -1.5 << " " << -0.5 << " "<< -0.5 << " " << 0.5;
      mInputStream.str(tmp.str());
    }
    takeAction("fractal-plane-size", mMenuData, mActionData);

    
    // fractal-calculate
    mOutputStream.clear();
    mInputStream.clear();
    mInputStream.str("");
    takeAction("fractal-calculate", mMenuData, mActionData);

    // grid-apply-color-table
    mOutputStream.clear();
    mInputStream.clear();
    mInputStream.str("");
    takeAction("grid-apply-color-table", mMenuData, mActionData);
}

void GlutApp::createComplexFractal() {
    // complex-fractal
    mOutputStream.clear();
    mInputStream.clear();
    mInputStream.str("");
    takeAction("complex-fractal", mMenuData, mActionData);
    
    // grid
    mOutputStream.clear();
    mInputStream.clear();
    {
      std::stringstream tmp;
      tmp << mHeight << " " << mWidth << " " << 50;
      mInputStream.str(tmp.str());
    }
    takeAction("grid", mMenuData, mActionData);


    // fractal-plane-size
    mOutputStream.clear();
    mInputStream.clear();
    {
      std::stringstream tmp;
      tmp << -0.5 << " " << 0.5 << " "<< -0.5 << " " << 0.5;
      mInputStream.str(tmp.str());
    }
    takeAction("fractal-plane-size", mMenuData, mActionData);

    
    // fractal-calculate
    mOutputStream.clear();
    mInputStream.clear();
    mInputStream.str("");
    takeAction("fractal-calculate", mMenuData, mActionData);

    // grid-apply-color-table
    mOutputStream.clear();
    mInputStream.clear();
    mInputStream.str("");
    takeAction("grid-apply-color-table", mMenuData, mActionData);
}

void GlutApp::createComplexFractal2() {
    // complex-fractal
    mOutputStream.clear();
    mInputStream.clear();
    mInputStream.str("");
    takeAction("complex-fractal", mMenuData, mActionData);
    
    // grid
    mOutputStream.clear();
    mInputStream.clear();
    {
      std::stringstream tmp;
      tmp << mHeight << " " << mWidth << " " << 200;
      mInputStream.str(tmp.str());
    }
    takeAction("grid", mMenuData, mActionData);


    // fractal-plane-size
    mOutputStream.clear();
    mInputStream.clear();
    {
      std::stringstream tmp;
      tmp << -1.0 << " " << 1.0 << " "<< -1.0 << " " << 1.0;
      mInputStream.str(tmp.str());
    }
    takeAction("fractal-plane-size", mMenuData, mActionData);

    
    // fractal-calculate
    mOutputStream.clear();
    mInputStream.clear();
    mInputStream.str("");
    takeAction("fractal-calculate", mMenuData, mActionData);

    // grid-apply-color-table
    mOutputStream.clear();
    mInputStream.clear();
    mInputStream.str("");
    takeAction("grid-apply-color-table", mMenuData, mActionData);
}

//???????????????????????????????????????????
void GlutApp::displayColorTable() {
    glBegin( GL_POINTS );
    for (int row = 0; row < mHeight; row++) {
        for (int col = 0; col < mWidth; col++) {
            int i = col * mActionData.getTable().getNumberOfColors() / mWidth;
            Color color = mActionData.getTable()[i];
            double r = color.getRed() / 255.0;
            double g = color.getGreen() / 255.0;
            double b = color.getBlue() / 255.0;
            color.setRed(r);
            color.setGreen(g);
            color.setBlue(b);
            //std::cout << "R: " << r << " G: " << g << " B: " <<  b << std::endl;
            glColor3d(r, g, b);
            glVertex2i(col, row);
        }
    }
    glEnd();
}
void GlutApp::setInteractionMode(InteractionMode mode) {
    mInteractionMode = mode;
    (void)mode;
}

//???????????????????????????????????????????
                      
void GlutApp::setColorTable() {
    // set-color-table-size
    mOutputStream.clear();
    mInputStream.clear();
    {
        std::stringstream tmp;
        tmp << mNumColor;
        mInputStream.str(tmp.str());
    }
    takeAction("set-color-table-size", mMenuData, mActionData);
    
    if (mHSVColor == false) {
        mOutputStream.clear();
        mInputStream.clear();
        {
            std::stringstream tmp;
            tmp << 0 << " " << mColor2.getRed() << " "<< mColor2.getGreen() << " " << mColor2.getBlue() << " " <<  (mNumColor/2)-1  << " " << mColor1.getRed() << " " << mColor1.getGreen() << " " << mColor1.getBlue();
            mInputStream.str(tmp.str());
        }
        takeAction("set-color-gradient", mMenuData, mActionData);
        
        // set-color-gradient
        mOutputStream.clear();
        mInputStream.clear();
        {
            std::stringstream tmp;
            tmp << mNumColor/2 << " " << mColor1.getRed() << " "<< mColor1.getGreen() << " " << mColor1.getBlue() << " " <<  mNumColor-1  << " " << mColor3.getRed() << " " << mColor3.getGreen() << " " << mColor3.getBlue();
            mInputStream.str(tmp.str());
        }
        takeAction("set-color-gradient", mMenuData, mActionData);
        
        /*
        // set-color-gradient
        mOutputStream.clear();
        mInputStream.clear();
        {
            std::stringstream tmp;
            tmp << 0 << " " << mColor2.getRed() << " "<< mColor2.getGreen() << " " << mColor2.getBlue() << " " <<  mNumColor-1  << " " << mColor3.getRed() << " " << mColor3.getGreen() << " " << mColor3.getBlue();
            mInputStream.str(tmp.str());
        }
        takeAction("set-color-gradient", mMenuData, mActionData);*/
        
        // set-color-gradient
    }
    else {
        //getHSV(mColor1.getRed(), mColor1.getGreen(), mColor1.getBlue(), mColor2.getRed(), mColor2.getGreen(), mColor2.getBlue() );
        mOutputStream.clear();
        mInputStream.clear();
        {
            std::stringstream tmp;
            tmp << 0 << " " << mColor3.getRed() << " "<< mColor3.getGreen() << " " << mColor3.getBlue() << " " <<  (mNumColor/2)-1  << " " << mColor1.getRed() << " " << mColor1.getGreen() << " " << mColor1.getBlue();
            mInputStream.str(tmp.str());
        }
        takeAction("set-color-gradient", mMenuData, mActionData);
        
        // set-color-gradient
        mOutputStream.clear();
        mInputStream.clear();
        {
            std::stringstream tmp;
            tmp << mNumColor/2 << " " << mColor1.getRed() << " "<< mColor1.getGreen() << " " << mColor1.getBlue() << " " <<  mNumColor-1  << " " << mColor2.getRed() << " " << mColor2.getGreen() << " " << mColor2.getBlue();
            mInputStream.str(tmp.str());
        }
        takeAction("set-color-gradient", mMenuData, mActionData);
    }
    }
void GlutApp::decreaseColorTableSize() {
    if (mNumColor > 10) {
        mNumColor /= 1.1;
        setColorTable();
        gridApplyColorTable();
    }
}
void GlutApp::increaseColorTableSize() {
    if (mNumColor < 1024) {
        mNumColor *= 1.1;
        setColorTable();
        gridApplyColorTable();
    }
}
void GlutApp::zoomIn() {
    double dx = (1.0 - 0.9)*(mMaxX-mMinX) / 2.0;
    double dy = (1.0 - 0.9)*(mMaxY-mMinY) / 2.0;
    
    if ((mMinX + dx) >= -2.0 && (mMaxX - dx) <= 2.0 && (mMinY + dy) >= -2.0 && (mMaxY - dy) <= 2.0 ) {
        mMinX += dx;
        mMaxX -= dx;
        mMinY += dy;
        mMaxY -= dy;
        //std::cout << "mMiny: " << mMinY << "\nmMaxY: " << mMaxY << "\nmMinX" <<  mMinX << "\nmMaxX: " << mMaxX << std::endl;
        fractalPlaneSize( mMinX, mMaxX, mMinY, mMaxY );
        fractalCalculate();
        gridApplyColorTable();
    }
}
void GlutApp::zoomOut() {
    double dx = (1.0 - 0.9)*(mMaxX-mMinX) / 2.0;
    double dy = (1.0 - 0.9)*(mMaxY - mMinY) / 2.0;
    if ((mMinX - dx) >= -2.0 && (mMaxX + dx) <= 2.0 && (mMinY - dy) >= -2.0 && (mMaxY + dy) <= 2.0 ) {
        mMinX -= dx;
        mMaxX += dx;
        mMinY -= dy;
        mMaxY += dy;
        //std::cout << "mMiny: " << mMinY << "\nmMaxY: " << mMaxY << "\nmMinX" << mMinX << "\nmMaxX: " << mMaxX << std::endl;
        fractalPlaneSize( mMinX, mMaxX, mMinY, mMaxY );
        fractalCalculate();
        gridApplyColorTable();
    }
}
void GlutApp::moveLeft() {
    double dx = (1.0 - 0.9)*(mMaxX-mMinX) / 2.0;
    if (mMinX - dx >= -2.0) {
        std::cout << "mMiny: " << mMinY << "\nmMaxY: " << mMaxY << "\nmMinX" << mMinX << "\nmMaxX: " << mMaxX << std::endl;
        mMinX -= dx;
        mMaxX -= dx;
        fractalPlaneSize(mMinX, mMaxX, mMinY, mMaxY);
        fractalCalculate();
        gridApplyColorTable();
        configureGrid(mMaxNumber);
    }
}

void GlutApp::moveRight() {
    double dx = (1.0 - 0.9)*(mMaxX-mMinX) / 2.0;
    if (mMaxX + dx <= 2.0) {
        mMinX += dx;
        mMaxX += dx;
        fractalPlaneSize(mMinX, mMaxX, mMinY, mMaxY);
        fractalCalculate();
        gridApplyColorTable();
        configureGrid(mMaxNumber);
    }
}
void GlutApp::moveDown() {
    double dy = (1.0 - 0.9)*(mMaxY-mMinY) / 2.0;
    if (mMinY - dy >= -2.0) {
        std::cout << "mMiny: " << mMinY << "\nmMaxY: " << mMaxY << "\nmMinX" << mMinX << "\nmMaxX: " << mMaxX << std::endl;
        std::cout << "down dy-" << dy << std::endl;
        mMinY -= dy;
        mMaxY -= dy;
        fractalPlaneSize(mMinX, mMaxX, mMinY, mMaxY);
        fractalCalculate();
        gridApplyColorTable();
        configureGrid(mMaxNumber);
    }
}
void GlutApp::moveUp() {
    double dy = (1.0 - 0.9)*(mMaxY-mMinY) / 2.0;
    if (mMaxY + dy <= 2.0) {
        mMinY += dy;
        mMaxY += dy;
        fractalPlaneSize(mMinX, mMaxX, mMinY, mMaxY);
        fractalCalculate();
        gridApplyColorTable();
        configureGrid(mMaxNumber);
    }
}
void GlutApp::setFractalMode(FractalMode mode) {
    mFractalMode = mode;
}
void GlutApp::increaseMaxNumber() {
    if (mMaxNumber < 2048) {
        mMaxNumber *= 1.1;
        configureGrid(mMaxNumber);
        fractalCalculate();
        gridApplyColorTable();
    }
}
void GlutApp::decreaseMaxNumber() {
    if (mMaxNumber > 11) {
        mMaxNumber /= 1.1;
        configureGrid(mMaxNumber);
        fractalCalculate();
        gridApplyColorTable();
    }
}
void GlutApp::setAB(int x, int y) {
    ComplexFractal *cf = dynamic_cast<ComplexFractal*>(&mActionData.getGrid());
    if ( mFractalMode == M_MANDELBROT && cf != 0 ) {
        this->mA = mMinX + x * cf->getDeltaX();
        this->mB = mMinY + y * cf->getDeltaY();
        //std::cout << "mA- " << mA << " mB- " << mB << std::endl;
    }
}
void GlutApp::resetPlane() {
    mMinX = -2.0;
    mMinY = -2.0;
    mMaxX = 2.0;
    mMaxY = 2.0;
    fractalPlaneSize(mMinX, mMaxX, mMinY, mMaxY);
    fractalCalculate();
    gridApplyColorTable();
}

//????????????????????????????????????
void GlutApp::createFractal() {
    if ( mFractalMode == M_MANDELBROT ) {
        selectMandelbrot();
        configureGrid(mMaxNumber);
        fractalPlaneSize(mMinX, mMaxX, mMinY, mMaxY);
        fractalCalculate();
        gridApplyColorTable();
        
        // ??
        //createMandelbrot();
        // ??
    }
    
    else if ( mFractalMode == M_JULIA ) {
        selectJulia();
        juliaParameters(mA, mB);
        fractalPlaneSize(mMinX, mMaxX, mMinY, mMaxY);
        fractalCalculate();
        gridApplyColorTable();
        configureGrid(mMaxNumber);
        
    }

    /*takeAction("complex-fractal", mMenuData, mActionData);
    takeAction("grid", mMenuData, mActionData);
    takeAction("fractal-plane-size", mMenuData, mActionData);
    takeAction("fractal-calculate", mMenuData, mActionData);
    takeAction("grid-apply-color-table", mMenuData, mActionData);*/
    
    // Shows a full Green Screen
    else if ( mFractalMode == M_COMPLEX ) {
        selectComplexFractal();
        configureGrid(mMaxNumber);
        fractalPlaneSize(mMinX, mMaxX, mMinY, mMaxY);
        fractalCalculate();
        gridApplyColorTable();
        
        // ??
        //createComplexFractal2();
        // ??
        
    }
}

    //std::cout << "mMinX: " << mMinX << " mMaxX: " << mMaxX << " mMinY: " << mMinY << " mMaxY: " << mMaxY << std::endl;
    
void GlutApp::increaseChannel(Color& color, int channel) {
    switch ( channel ) {
        case 0:
            if ((color.getRed() + 10) <= 255 ) {
                color.setRed(color.getRed() + 10);
            }
            else {
                color.setRed(255);
            }
            break;
        case 1:
            if ((color.getGreen() + 10) <= 255 ) {
                color.setGreen(color.getGreen() + 10);
            }
            else {
                color.setGreen(255);
            }
            break;
        case 2:
            if ((color.getBlue() + 10) <= 255 ) {
                color.setBlue(color.getBlue() + 10);
            }
            else {
                color.setBlue(255);
            }
            break;
        default:
            std::cout << "Not a valid channel! " << std::endl;
    }
}
void GlutApp::decreaseChannel(Color& color, int channel) {
    switch ( channel ) {
        case 0:
            if ((color.getRed() - 10) >= 0 ) {
                color.setRed(color.getRed() - 10);
            }
            else {
                color.setRed(255);
            }
            break;
        case 1:
            if ((color.getGreen() - 10) >= 0 ) {
                color.setGreen(color.getGreen() - 10);
            }
            else {
                color.setGreen(255);
            }
            break;
        case 2:
            if ((color.getBlue() - 10) >= 0 ) {
                color.setBlue(color.getBlue() - 10);
            }
            else {
                color.setBlue(255);
            }
            break;
        default:
            std::cout << "Not a valid channel! " << std::endl;
    }
}

// check static color
Color& GlutApp::fetchColor() {
    if (mInteractionMode == IM_COLOR1) {
        return mColor1;
    }
    else if (mInteractionMode == IM_COLOR2) {
        return mColor2;
    }
    else if (mInteractionMode == IM_COLOR3) {
        return mColor3;
    }
    else {
        static Color color;
        return color;
    }
}
    
void GlutApp::increaseRed() {
    increaseChannel(fetchColor(), 0 );
}
void GlutApp::decreaseRed() {
    decreaseChannel(fetchColor(), 0 );
}
void GlutApp::increaseGreen() {
    increaseChannel(fetchColor(), 1 );
}
void GlutApp::decreaseGreen() {
    decreaseChannel(fetchColor(), 1 );
}
void GlutApp::increaseBlue() {
    increaseChannel(fetchColor(), 2 );
}
void GlutApp::decreaseBlue() {
    decreaseChannel(fetchColor(), 2 );
}

void GlutApp::toggleHSVColor() {
    if (mHSVColor == false) {
        mHSVColor = true;
        setColorTable();
        gridApplyColorTable();
    }
    else {
        mHSVColor = false;
        setColorTable();
        gridApplyColorTable();
    }
}

GCC := g++ -std=c++11
LDFLAGS        := -lpthread

all: ppm_menu image_file ascii_image hello questions_3

ppm_menu: ppm_menu.o ActionData.o MenuData.o Image.o PPM.o controllers.o image_drawing.o image_output.o user_io.o image_filters.o NumberGrid.o ColorTable.o ComplexFractal.o JuliaSet.o MandelbrotSet.o ThreadedGrid.o
	$(GCC) $^ -o ppm_menu $(LDFLAGS)


four_square: four_square.o user_io.o controllers.o image_output.o image_drawing.o Image.o PPM.o ActionData.o MenuData.o image_filters.o NumberGrid.o ColorTable.o ComplexFractal.o JuliaSet.o MandelbrotSet.o ThreadedGrid.o
	$(GCC) $^ -o four_square $(LDFLAGS)

image_file: image_file.o user_io.o controllers.o image_output.o image_drawing.o Image.o PPM.o ActionData.o MenuData.o image_filters.o NumberGrid.o ColorTable.o ComplexFractal.o JuliaSet.o MandelbrotSet.o ThreadedGrid.o
	$(GCC) $^ -o image_file $(LDFLAGS)

ascii_image: ascii_image.o user_io.o controllers.o image_output.o image_drawing.o Image.o PPM.o ActionData.o MenuData.o image_filters.o NumberGrid.o ColorTable.o ComplexFractal.o JuliaSet.o MandelbrotSet.o ThreadedGrid.o
	$(GCC) $^ -o ascii_image $(LDFLAGS)
questions_3: questions_3.o user_io.o controllers.o image_output.o image_drawing.o Image.o PPM.o ActionData.o MenuData.o image_filters.o NumberGrid.o ColorTable.o ComplexFractal.o JuliaSet.o MandelbrotSet.o ThreadedGrid.o
	$(GCC) $^ -o questions_3 $(LDFLAGS)
MandelbrotSet.o: MandelbrotSet.cpp MandelbrotSet.h
	$(GCC) -c $< 
ThreadedGrid.o: ThreadedGrid.cpp ThreadedGrid.h ThreadedVector.h
	$(GCC) -c $< $(LDFLAGS)
JuliaSet.o: JuliaSet.cpp JuliaSet.h
	$(GCC) -c $< 
ComplexFractal.o: ComplexFractal.cpp ComplexFractal.h
	$(GCC) -c $<
ColorTable.o: ColorTable.cpp ColorTable.h
	$(GCC) -c $<
NumberGrid.o: NumberGrid.cpp NumberGrid.h
	$(GCC) -c $<
ppm_menu.o: ppm_menu.cpp
	$(GCC) -c $<
hello: hello.o
	$(GCC) $^ -o hello
image_filters.o: image_filters.cpp image_menu.h
	$(GCC) -c $<
ActionData.o: ActionData.cpp ActionData.h
	$(GCC) -c $<
MenuData.o: MenuData.cpp MenuData.h
	$(GCC) -c $<
four_square.o: four_square.cpp
	$(GCC) -c $<
PPM.o: PPM.cpp PPM.h
	$(GCC) -c $<
image_file.o: image_file.cpp
	$(GCC) -c $<
Image.o: Image.cpp Image.h
	$(GCC) -c $<
image_output.o: image_output.cpp image_menu.h
	$(GCC) -c $<
image_drawing.o: image_drawing.cpp image_menu.h
	$(GCC) -c $<
ascii_image.o: ascii_image.cpp
	$(GCC) -c $<
hello.o: hello.cpp
	$(GCC) -c $<
questions_3.o: questions_3.cpp image_menu.h ActionData.h MenuData.h
	$(GCC) -c $<
user_io.o: user_io.cpp 
	$(GCC) -c $<
controllers.o: controllers.cpp image_menu.h
	$(GCC) -c $<

clean:
	-rm *.o *.ppm ppm_menu ascii_image hello questions_3 image_file four_square

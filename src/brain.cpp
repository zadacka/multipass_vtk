#include <vtkSmartPointer.h>
#include "vtkConeSource.h"
#include "vtkPolyDataMapper.h"
#include "vtkRenderWindow.h"
#include "vtkCamera.h"
#include "vtkActor.h"
#include "vtkRenderer.h"
#include <vtkRenderWindowInteractor.h>
#include <vtkCallbackCommand.h>
#include "vtkGenericDataObjectReader.h"

int main()
{

    std::string inputFilename = "/home/azawadzki/Desktop/mitk/bin/btain.vtk";
 
    // read data
    vtkSmartPointer<vtkGenericDataObjectReader> reader = 
	vtkSmartPointer<vtkGenericDataObjectReader>::New();
    reader->SetFileName(inputFilename.c_str());
    reader->Update();
 
    // polydata
    vtkSmartPointer<vtkPolyData> output = reader->GetPolyDataOutput();

    // mapper
    vtkSmartPointer<vtkPolyDataMapper> mapper = 
	vtkSmartPointer<vtkPolyDataMapper>::New();
    mapper->SetInputConnection(output->GetProducerPort());

    // actor
    vtkSmartPointer<vtkActor> actor = 
	vtkSmartPointer<vtkActor>::New();
    actor->SetMapper( mapper );

    // renderer
    vtkSmartPointer<vtkRenderer> renderer = 
	vtkSmartPointer<vtkRenderer>::New();
    renderer->AddActor( actor );
    renderer->SetBackground( 0.1, 0.2, 0.4 );

    // render window
    vtkSmartPointer<vtkRenderWindow> render_window = 
	vtkSmartPointer<vtkRenderWindow>::New();
    render_window->SetSize( 1280, 800 );
    render_window->AddRenderer( renderer );

    // interactor
    vtkSmartPointer<vtkRenderWindowInteractor> renderWindowInteractor = 
	vtkSmartPointer<vtkRenderWindowInteractor>::New();
    renderWindowInteractor->SetRenderWindow(render_window);

    // ... and go!
    render_window->Render();
    renderWindowInteractor->Start();

    return 0;
}



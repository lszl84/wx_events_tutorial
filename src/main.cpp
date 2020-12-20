#include <wx/wx.h>
#include <wx/listctrl.h>

class MyApp : public wxApp
{
public:
    virtual bool OnInit();
};

wxIMPLEMENT_APP(MyApp);

class MyFrame : public wxFrame
{
public:
    MyFrame(const wxString &title, const wxPoint &pos, const wxSize &size);
};

bool MyApp::OnInit()
{
    MyFrame *frame = new MyFrame("Hello World", wxDefaultPosition, wxDefaultSize);
    frame->Show(true);
    return true;
}

MyFrame::MyFrame(const wxString &title, const wxPoint &pos, const wxSize &size) : wxFrame(nullptr, wxID_ANY, title, pos, size)
{
    auto button = new wxButton(this, wxID_ANY, "Click me!");

    auto sizer = new wxBoxSizer(wxHORIZONTAL);
    sizer->Add(button, 0, wxCENTER | wxALL, 100);
    SetSizerAndFit(sizer);
}

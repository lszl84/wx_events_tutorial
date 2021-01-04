#include <wx/wx.h>

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

private:
    void OnClick(wxCommandEvent &);

    wxDECLARE_EVENT_TABLE();
};

// clang-format off

wxBEGIN_EVENT_TABLE(MyFrame, wxFrame)
EVT_BUTTON(wxID_ANY, MyFrame::OnClick)
wxEND_EVENT_TABLE()

; // clang-format on

bool MyApp::OnInit()
{
    MyFrame *frame = new MyFrame("Hello World", wxDefaultPosition, wxDefaultSize);
    frame->Show(true);
    return true;
}

MyFrame::MyFrame(const wxString &title, const wxPoint &pos, const wxSize &size) : wxFrame(nullptr, wxID_ANY, title, pos, size)
{
    auto button = new wxButton(this, wxID_ANY, "Click me!");
    auto otherButton = new wxButton(this, wxID_ANY, "Or me!");

    auto sizer = new wxBoxSizer(wxHORIZONTAL);
    sizer->Add(button, 0, wxCENTER | wxALL, 100);
    sizer->Add(otherButton, 0, wxCENTER | wxALL, 100);
    SetSizerAndFit(sizer);
}

void MyFrame::OnClick(wxCommandEvent &e)
{
    std::cout << "Hey, button clicked. It's id = " << e.GetId() << std::endl;
}

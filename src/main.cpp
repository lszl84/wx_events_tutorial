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
    void OnOtherClick(wxCommandEvent &);

    wxDECLARE_EVENT_TABLE();
};

enum ButtonId
{
    first_button_id = wxID_LAST + 1,
    other_button_id
};

// clang-format off

wxBEGIN_EVENT_TABLE(MyFrame, wxFrame)
EVT_BUTTON(wxID_ANY, MyFrame::OnClick)
EVT_BUTTON(other_button_id, MyFrame::OnOtherClick)
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
    auto button = new wxButton(this, first_button_id, "Click me!");
    auto otherButton = new wxButton(this, other_button_id, "Or me!");

    auto sizer = new wxBoxSizer(wxHORIZONTAL);
    sizer->Add(button, 0, wxCENTER | wxALL, 100);
    sizer->Add(otherButton, 0, wxCENTER | wxALL, 100);
    SetSizerAndFit(sizer);
}

void MyFrame::OnClick(wxCommandEvent &e)
{
    std::cout << "Hey, button clicked. It's id = " << e.GetId() << std::endl;
    e.Skip();
}

void MyFrame::OnOtherClick(wxCommandEvent &e)
{
    std::cout << "Other button clicked. It's id = " << e.GetId() << std::endl;
}

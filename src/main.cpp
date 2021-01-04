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

enum ButtonId
{
    first_button_id = wxID_LAST + 1,
    other_button_id
};

// clang-format off

wxBEGIN_EVENT_TABLE(MyFrame, wxFrame)
EVT_BUTTON(wxID_ANY, MyFrame::OnClick)
wxEND_EVENT_TABLE()

; // clang-format on

class MyPanel : public wxPanel
{
public:
    MyPanel(wxWindow *parent);

private:
    void OnClick(wxCommandEvent &);
    wxDECLARE_EVENT_TABLE();
};

MyPanel::MyPanel(wxWindow *parent) : wxPanel(parent)
{
    this->SetBackgroundColour(wxColor(200, 100, 100));
}

void MyPanel::OnClick(wxCommandEvent &e)
{
    std::cout << "PANEL OnClick, id = " << e.GetId() << std::endl;
    e.Skip();
}

// clang-format off

wxBEGIN_EVENT_TABLE(MyPanel, wxPanel)
EVT_BUTTON(wxID_ANY, MyPanel::OnClick)
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
    auto panel = new MyPanel(this);

    auto button = new wxButton(panel, first_button_id, "Click me!");
    auto panelSizer = new wxBoxSizer(wxHORIZONTAL);
    panelSizer->Add(button, 0, wxCENTER | wxALL, 100);
    panel->SetSizerAndFit(panelSizer);

    auto otherButton = new wxButton(this, other_button_id, "Or me!");

    auto sizer = new wxBoxSizer(wxHORIZONTAL);
    sizer->Add(panel, 0, wxEXPAND);
    sizer->Add(otherButton, 0, wxCENTER | wxALL, 100);
    SetSizerAndFit(sizer);
}

void MyFrame::OnClick(wxCommandEvent &e)
{
    std::cout << "Hey, button clicked. It's id = " << e.GetId() << std::endl;
    e.Skip();
}

object Dinner: TDinner
  Left = 0
  Top = 0
  Hint = '1'
  Caption = #1057#1090#1086#1083#1086#1074#1072#1103
  ClientHeight = 198
  ClientWidth = 288
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  Menu = MainMenu1
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 1
    Top = 156
    Width = 140
    Height = 13
    Caption = #1042#1074#1077#1076#1080#1090#1077' '#1082#1086#1083'-'#1074#1086' '#1092#1080#1083#1086#1089#1086#1092#1086#1074
  end
  object Events: TMemo
    Left = 0
    Top = 0
    Width = 288
    Height = 145
    Align = alTop
    ScrollBars = ssVertical
    TabOrder = 0
    ExplicitWidth = 287
  end
  object Edit1: TEdit
    Left = 145
    Top = 151
    Width = 72
    Height = 21
    Hint = #1052#1072#1082#1089#1080#1084#1072#1083#1100#1085#1086#1077' '#1095#1080#1089#1083#1086' 10'
    ParentShowHint = False
    ShowHint = True
    TabOrder = 1
  end
  object Button1: TButton
    Left = 220
    Top = 149
    Width = 63
    Height = 25
    Caption = #1042#1074#1086#1076
    TabOrder = 2
    OnClick = Button1Click
  end
  object MainMenu1: TMainMenu
    Left = 296
    Top = 72
    object N1: TMenuItem
      Caption = #1047#1072#1087#1091#1089#1082
      Enabled = False
      OnClick = N1Click
    end
    object N2: TMenuItem
      Caption = #1057#1087#1088#1072#1074#1082#1072
      OnClick = N2Click
    end
    object N3: TMenuItem
      Caption = #1042#1099#1093#1086#1076
      OnClick = N3Click
    end
  end
  object Timer1: TTimer
    Interval = 15000
    Left = 208
    Top = 48
  end
end

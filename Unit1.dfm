object Form1: TForm1
  Left = 0
  Top = 0
  BorderIcons = [biSystemMenu]
  BorderStyle = bsSingle
  Caption = #1042#1072#1088#1080#1072#1085#1090' 4. '#1041#1077#1083#1103#1082#1086#1074' '#1070'.'#1052'.'
  ClientHeight = 482
  ClientWidth = 872
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 872
    Height = 49
    Align = alTop
    Caption = 'Panel1'
    ShowCaption = False
    TabOrder = 0
    object SpeedButton1: TSpeedButton
      Left = 7
      Top = 8
      Width = 105
      Height = 35
      Action = PrAction
    end
    object SpeedButton2: TSpeedButton
      Left = 118
      Top = 8
      Width = 97
      Height = 35
      Action = PrStop
      Caption = #1054#1089#1090#1072#1085#1086#1074#1080#1090#1100
    end
    object Label1: TLabel
      Left = 221
      Top = 16
      Width = 197
      Height = 23
      Caption = #1055#1077#1088#1080#1086#1076' ('#1084#1080#1083#1080#1089#1077#1082#1091#1085#1076'):'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -19
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
      Layout = tlCenter
    end
    object Label2: TLabel
      Left = 495
      Top = 16
      Width = 146
      Height = 23
      Caption = #1056#1072#1079#1084#1077#1088' '#1084#1072#1089#1089#1080#1074#1072':'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -19
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
    end
    object Edit1: TEdit
      Left = 424
      Top = 8
      Width = 65
      Height = 31
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -19
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
      TabOrder = 0
    end
    object Edit2: TEdit
      Left = 647
      Top = 8
      Width = 65
      Height = 31
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -19
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
      TabOrder = 1
    end
  end
  object Panel2: TPanel
    Left = 0
    Top = 49
    Width = 872
    Height = 433
    Align = alClient
    Caption = 'Panel2'
    ShowCaption = False
    TabOrder = 1
    object GroupBox1: TGroupBox
      Left = 7
      Top = 6
      Width = 208
      Height = 387
      Caption = #1052#1072#1089#1089#1080#1074' A'
      TabOrder = 0
      object Memo1: TMemo
        Left = 2
        Top = 15
        Width = 204
        Height = 370
        Align = alClient
        ReadOnly = True
        ScrollBars = ssVertical
        TabOrder = 0
      end
    end
    object GroupBox2: TGroupBox
      Left = 221
      Top = 6
      Width = 208
      Height = 387
      Caption = #1047#1072#1076#1072#1085#1080#1077' B'
      TabOrder = 1
      object Memo2: TMemo
        Left = 2
        Top = 15
        Width = 204
        Height = 370
        Align = alClient
        ReadOnly = True
        ScrollBars = ssVertical
        TabOrder = 0
      end
    end
    object GroupBox3: TGroupBox
      Left = 435
      Top = 6
      Width = 208
      Height = 387
      Caption = #1047#1072#1076#1072#1085#1080#1077' C'
      TabOrder = 2
      object Memo3: TMemo
        Left = 2
        Top = 15
        Width = 204
        Height = 370
        Align = alClient
        ReadOnly = True
        ScrollBars = ssVertical
        TabOrder = 0
      end
    end
    object Memo4: TMemo
      Left = 649
      Top = 6
      Width = 216
      Height = 387
      Color = cl3DLight
      Enabled = False
      Lines.Strings = (
        #1056#1072#1079#1088#1072#1073#1086#1090#1072#1090#1100' '#1087#1088#1086#1075#1088#1072#1084#1084#1091', '#1082#1086#1090#1086#1088#1072#1103' '
        #1089#1086#1079#1076#1072#1105#1090' '#1074' '#1086#1090#1076#1077#1083#1100#1085#1086#1084' '#1087#1086#1090#1086#1082#1091' '
        #1089#1083#1091#1095#1072#1081#1085#1099#1081' '#1084#1072#1089#1089#1080#1074' A '#1080#1079' N '#1094#1077#1083#1099#1093' '#1095#1080#1089#1077#1083' '#1074' '
        #1076#1080#1072#1087#1072#1079#1086#1085#1077' '#1086#1090' -999 '#1076#1086' 999 '#1074#1099#1074#1086#1076#1080#1090' '#1085#1072' '
        #1101#1082#1088#1072#1085' '#1101#1090#1080' '#1095#1080#1089#1083#1072'. '
        #1057#1086#1079#1076#1072#1085#1080#1077' '#1080' '#1074#1099#1074#1086#1076' '#1101#1083#1077#1084#1077#1085#1090#1086#1074' '#1084#1072#1089#1089#1080#1074#1072' '
        #1087#1088#1086#1080#1079#1074#1086#1076#1080#1090#1089#1103' '#1095#1077#1088#1077#1079' '#1079#1072#1076#1072#1085#1085#1086#1077' '#1074#1088#1077#1084#1103' T, '
        'N '#1080' T '#1074#1074#1086#1076#1103#1090#1089#1103' '#1087#1086#1083#1100#1079#1086#1074#1072#1090#1077#1083#1077#1084' '#1076#1086' '
        #1079#1072#1087#1091#1089#1082#1072' '#1087#1088#1086#1094#1077#1089#1089#1072'. '
        #1052#1072#1089#1089#1080#1074' '#1086#1073#1088#1072#1073#1072#1090#1099#1074#1072#1077#1090#1089#1103' '#1076#1074#1091#1084#1103' '#1076#1088#1091#1075#1080#1084#1080' '
        #1087#1086#1090#1086#1082#1072#1084#1080' B '#1080' C, '#1088#1072#1073#1086#1090#1072#1102#1097#1080#1084#1080' '
        #1087#1072#1088#1072#1083#1083#1077#1083#1100#1085#1086' '#1089' '#1087#1086#1090#1086#1082#1086#1084', '#1089#1086#1079#1076#1072#1102#1097#1080#1084' '
        #1084#1072#1089#1089#1080#1074'. '#1042#1089#1077' '#1087#1086#1090#1086#1082#1080' '#1074#1099#1074#1086#1076#1103#1090' '
        #1088#1077#1079#1091#1083#1100#1090#1072#1090#1099' '#1089#1074#1086#1077#1081' '#1088#1072#1073#1086#1090#1099' '#1074' '#1090#1077#1082#1089#1090#1086#1074#1099#1077' '
        #1086#1082#1085#1072', '#1082#1072#1078#1076#1099#1081' '#1087#1086#1090#1086#1082' '#1074' '#1089#1074#1086#1105' '#1086#1082#1085#1086'.'
        #1047#1072#1076#1072#1085#1080#1077' B: '#1042#1099#1095#1080#1089#1083#1077#1085#1080#1077' '#1084#1080#1085#1080#1084#1072#1083#1100#1085#1086#1075#1086' '#1080' '
        #1084#1072#1082#1089#1080#1084#1072#1083#1100#1085#1086#1075#1086' '#1079#1085#1072#1095#1077#1085#1080#1103
        #1047#1072#1076#1072#1085#1080#1077' C: '#1042#1099#1095#1080#1089#1083#1077#1085#1080#1077' '#1086#1090#1082#1083#1086#1085#1077#1085#1080#1081' '
        #1082#1072#1078#1076#1086#1075#1086' '#1079#1085#1072#1095#1077#1085#1080#1103' '#1086#1090' '#1089#1088#1077#1076#1085#1077#1075#1086' '
        #1072#1088#1080#1092#1084#1077#1090#1080#1095#1077#1089#1082#1086#1075#1086)
      TabOrder = 3
    end
    object ProgressBar1: TProgressBar
      Left = 7
      Top = 399
      Width = 858
      Height = 24
      TabOrder = 4
    end
  end
  object ActionList1: TActionList
    Left = 816
    Top = 400
    object PrAction: TAction
      Caption = #1047#1072#1087#1091#1089#1090#1080#1090#1100
      OnExecute = PrActionExecute
    end
    object PrStop: TAction
      Caption = 'PrStop'
      OnExecute = PrStopExecute
    end
  end
end

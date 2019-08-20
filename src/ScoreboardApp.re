open Types;

module MenuIcon = MscharleyBsMaterialUiIcons.RadioButtonUnchecked.Filled;
module KeyboardArrowRight = MscharleyBsMaterialUiIcons.KeyboardArrowRight.Outlined;
module KeyboardArrowLeft = MscharleyBsMaterialUiIcons.KeyboardArrowLeft.Outlined;
module EditIcon = MscharleyBsMaterialUiIcons.Edit.Filled;

let str = ReasonReact.string;
let str_int = number => str(string_of_int(number));

let styleStepper =
  ReactDOMRe.Style.make(
    ~flexGrow="1",
    ~position="absolute",
    ~bottom="0px",
    ~right="0px",
    ~width="100%",
    (),
  );

let showFab = (index: int) => {
  switch (index) {
  | 0 => React.string("")
  | _ =>
    <MaterialUi_Fab
      style={ReactDOMRe.Style.make(
        ~position="absolute",
        ~right="20px",
        ~bottom="70px",
        (),
      )}>
      <EditIcon />
    </MaterialUi_Fab>
  };
};

let setHeight = ReactDOMRe.Style.make(~height="100%", ());

let indexToPage = (index: int): page =>
  switch (index) {
  | 0 => GamePage
  | 1 => EditHP1Page
  | 2 => EditHP2Page
  | 3 => EditAP1Page
  | 4 => EditAP2Page
  | _ => GamePage
  };

let pageToTitle = (~state: state, ~player: players, ~page: page): string => {
  switch (page) {
  | EditHP1Page
  | EditHP2Page
  | EditAP1Page
  | EditAP2Page =>
    let inde = PlayerInfo.info(~playerType=Player1Hometeam, ~state);
    let info = PlayerInfo.info(~playerType=player, ~state);
    let title = {
      info.team ++ " - " ++ info.playerStringCap;
    };
    title;
  | GamePage => "Game"
  };
};

let pageToPlayer = (page: page) =>
  switch (page) {
  | EditHP1Page => Player1Hometeam
  | EditHP2Page => Player2Hometeam
  | EditAP1Page => Player1Awayteam
  | EditAP2Page => Player2Awayteam
  | _ =>
    Js.log("Error: pageToPlayer failed, falback to Player1Hometeam");
    Player1Hometeam;
  };

[@react.component]
let make = () => {
  let (state, dispatch) =
    React.useReducer(Types.reducer, Types.initialState);
  let (index, setIndex) = React.useState(() => 0);
  let handleChangeIndex = index => setIndex(_ => index);
  let page = indexToPage(index);
  let player = pageToPlayer(page);
  let title = pageToTitle(~state, ~player, ~page);
  let fab = showFab(index);
  //TODO: fix hardcoded value

  let mobileStepper =
    <MaterialUi_MobileStepper
      variant=`Dots
      steps={`Int(4)}
      position=`Static
      style=styleStepper
      activeStep={`Int(index)}
      nextButton={
        <MaterialUi_Button size=`Small disabled=false>
          {ReasonReact.string("Next")}
          <KeyboardArrowRight />
        </MaterialUi_Button>
      }
      backButton={
        <MaterialUi_Button size=`Small disabled=false>
          <KeyboardArrowLeft />
          {ReasonReact.string("Back")}
        </MaterialUi_Button>
      }
    />;
  <React.Fragment>
    <MaterialUi_CssBaseline />
    <AppBar title />
    <ReactSwipeableViews
      style=setHeight
      containerStyle=setHeight
      slideStyle=setHeight
      index
      onChangeIndex=handleChangeIndex>
      <Game state dispatch />
      <TeamSettingsTeam state dispatch player=Player1Hometeam />
      <TeamSettingsTeam state dispatch player=Player2Hometeam />
      <TeamSettingsTeam state dispatch player=Player1Awayteam />
      <TeamSettingsTeam state dispatch player=Player2Awayteam />
    </ReactSwipeableViews>
    fab
    mobileStepper
  </React.Fragment>;
};
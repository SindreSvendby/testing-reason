[%%debugger.chrome];
open Types;
open PlayerInfo;

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

let showEditFab = (~page: page, ~dispatch) => {
  switch (page) {
  | GamePage => React.string("")
  | EditHP1Page
  | EditHP2Page
  | EditAP1Page
  | EditAP2Page =>
    <MaterialUi_Fab
      onClick={_event => dispatch(Edit(Player))}
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

let setHeight = ReactDOMRe.Style.make(~minHeight="100vh", ());

let pageToTitle = (~state: state, ~player: players, ~page: page): string => {
  switch (page) {
  | EditHP1Page
  | EditHP2Page
  | EditAP1Page
  | EditAP2Page =>
    let info = PlayerInfo.info(~playerType=player, ~state);
    let title = {
      info.team ++ " - " ++ info.playerStringCap;
    };
    title;
  | GamePage => "Game"
  };
};

[@react.component]
let make = () => {
  let (state, dispatch) =
    React.useReducer(Types.reducer, Types.initialState);
  let (index, setIndex) = React.useState(() => 0);
  let handleChangeIndex = (index, _, _) => setIndex(_ => index);
  let page = indexToPage(index);
  let player = pageToPlayer(page);
  Js.log("Player:");
  Js.log(player);
  Js.log("index:" ++ string_of_int(index));
  let title = pageToTitle(~state, ~player, ~page);
  let fab = showEditFab(~page, ~dispatch);
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
          "Next"->ReasonReact.string
          <KeyboardArrowRight />
        </MaterialUi_Button>
      }
      backButton={
        <MaterialUi_Button size=`Small disabled=false>
          <KeyboardArrowLeft />
          "Back"->ReasonReact.string
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
      <TeamSettingsTeam state dispatch player=Player1Hometeam index />
      <TeamSettingsTeam state dispatch player=Player2Hometeam index />
      <TeamSettingsTeam state dispatch player=Player1Awayteam index />
      <TeamSettingsTeam state dispatch player=Player2Awayteam index />
    </ReactSwipeableViews>
    fab
    mobileStepper
  </React.Fragment>;
};
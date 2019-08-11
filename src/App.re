open MscharleyBsMaterialUiIcons;

module MenuIcon = Menu.Filled;

let str = ReasonReact.string;
let str_int = number => str(string_of_int(number));

type screen =
  | GameScreen
  | HometeamScreen
  | AwayScreen;

type player =
  | Player1Hometeam
  | Player2Hometeam
  | Player1Awayteam
  | Player2Awayteam;

type order =
  | One
  | Two
  | Three
  | Four;

/* Action declaration */
type action =
  | AddPointsHometeam
  | AddPointsAwayteam
  | ChangeNamePlayer1Hometeam(string)
  | ChangeNamePlayer2Hometeam(string)
  | ChangeNamePlayer1Awayteam(string)
  | ChangeNamePlayer2Awayteam(string)
  | UNDO
  | AddNote(string)
  | ChangeJerseyColorPlayer1Hometeam(string)
  | ChangeJerseyColorPlayer2Hometeam(string)
  | ChangeJerseyColorPlayer1Awayteam(string)
  | ChangeJerseyColorPlayer2Awayteam(string)
  | ShowView(screen)
  | ServiceOrder(player);

/* State declaration */
type state = {
  scoreH: int,
  scoreA: int,
  namePlayer1Hometeam: string,
  namePlayer2Hometeam: string,
  namePlayer1Awayteam: string,
  namePlayer2Awayteam: string,
  jerseyColorPlayer1Hometeam: string,
  jerseyColorPlayer2Hometeam: string,
  jerseyColorPlayer1Awayteam: string,
  jerseyColorPlayer2Awayteam: string,
  notes: list(string),
  actions: list(action),
  screen,
  serviceOrderSet1: list(player),
  serviceOrderSet2: list(player),
  serviceOrderSet3: list(player),
};

let initialState: state = {
  scoreA: 0,
  scoreH: 1,
  namePlayer1Hometeam: "",
  namePlayer2Hometeam: "",
  namePlayer1Awayteam: "",
  namePlayer2Awayteam: "",
  jerseyColorPlayer1Hometeam: "",
  jerseyColorPlayer2Hometeam: "",
  jerseyColorPlayer1Awayteam: "",
  jerseyColorPlayer2Awayteam: "",
  notes: [],
  actions: [],
  screen: GameScreen,
  serviceOrderSet1: [],
  serviceOrderSet2: [],
  serviceOrderSet3: [],
};

let reducer = (state, action) => {
  Js.log(state);
  switch (action) {
  | AddPointsHometeam => {...state, scoreH: state.scoreH + 1}
  | AddPointsAwayteam => {...state, scoreA: state.scoreA + 1}
  | ChangeNamePlayer1Hometeam(value) => {
      ...state,
      namePlayer1Hometeam: value,
    }
  | ChangeNamePlayer2Hometeam(value) => {
      ...state,
      namePlayer2Hometeam: value,
    }
  | ChangeNamePlayer1Awayteam(value) => {
      ...state,
      namePlayer1Awayteam: value,
    }
  | ChangeNamePlayer2Awayteam(value) => {
      ...state,
      namePlayer2Awayteam: value,
    }
  | ChangeJerseyColorPlayer1Hometeam(value) => {
      ...state,
      jerseyColorPlayer1Hometeam: value,
    }
  | ChangeJerseyColorPlayer2Hometeam(value) => {
      ...state,
      jerseyColorPlayer2Hometeam: value,
    }
  | ChangeJerseyColorPlayer1Awayteam(value) => {
      ...state,
      jerseyColorPlayer1Awayteam: value,
    }
  | ChangeJerseyColorPlayer2Awayteam(value) => {
      ...state,
      jerseyColorPlayer2Awayteam: value,
    }
  | UNDO => {...state, actions: [UNDO, ...state.actions]}
  | AddNote(value) => {...state, jerseyColorPlayer2Awayteam: value}
  | ServiceOrder(player) =>
    switch (player) {
    | Player1Hometeam => {
        ...state,
        serviceOrderSet1: [Player2Hometeam, ...state.serviceOrderSet1],
      }
    | Player2Hometeam => {
        ...state,
        serviceOrderSet1: [Player2Hometeam, ...state.serviceOrderSet1],
      }
    | Player1Awayteam => {
        ...state,
        serviceOrderSet1: [Player1Awayteam, ...state.serviceOrderSet1],
      }
    | Player2Awayteam => {
        ...state,
        serviceOrderSet1: [Player2Awayteam, ...state.serviceOrderSet1],
      }
    }
  | ShowView(screen) => {...state, screen}
  };
};

[@react.component]
let make = () => {
  let (state, dispatch) = React.useReducer(reducer, initialState);
  <div>
    <div className="test" />
    <MaterialUi_AppBar position=`Static>
      <MaterialUi_Toolbar>
        <MaterialUi_IconButton edge=`Start color=`Inherit>
          <MenuIcon />
        </MaterialUi_IconButton>
        <MaterialUi_Typography variant=`H6> "News" </MaterialUi_Typography>
        <MaterialUi_Button color=`Inherit> "Login" </MaterialUi_Button>
      </MaterialUi_Toolbar>
    </MaterialUi_AppBar>
    <MaterialUi_Grid `Container spacing=3>
      <MaterialUi_Grid item xs=12>
        <MaterialUi_Paper> "xs=12" </MaterialUi_Paper>
      </MaterialUi_Grid>
      <MaterialUi_Grid item xs=6>
        <MaterialUi_Paper> "xs=6" </MaterialUi_Paper>
      </MaterialUi_Grid>
      <MaterialUi_Grid item xs=6>
        <MaterialUi_Paper> "xs=6" </MaterialUi_Paper>
      </MaterialUi_Grid>
    </MaterialUi_Grid>
    <div> {str_int(state.scoreH)} </div>
    <button onClick={_event => dispatch(AddPointsHometeam)}>
      {str("Add Point Hometeam")}
    </button>
    <div> {str_int(state.scoreA)} </div>
    <button onClick={_event => dispatch(AddPointsAwayteam)}>
      {str("Add Point Awayteam")}
    </button>
    <form>
      <label htmlFor="player1Hometeam"> {str("Player1 HomeTeam")} </label>
      <input
        name="player1Hometeam"
        onChange={event =>
          dispatch(
            ChangeNamePlayer1Hometeam(ReactEvent.Form.target(event)##value),
          )
        }
      />
    </form>
    <form>
      <label htmlFor="player2Hometeam"> {str("Player2 HomeTeam")} </label>
      <input
        name="player2Hometeam"
        onChange={event =>
          dispatch(
            ChangeNamePlayer2Awayteam(ReactEvent.Form.target(event)##value),
          )
        }
      />
    </form>
    <form>
      <label htmlFor="player1Awayteam"> {str("Player1 Awayteam")} </label>
      <input
        name="player1Awayteam"
        onChange={event =>
          dispatch(
            ChangeNamePlayer1Awayteam(ReactEvent.Form.target(event)##value),
          )
        }
      />
    </form>
    <MaterialUi_Typography variant=`H6> "Icon Types:" </MaterialUi_Typography>
    <form>
      <label htmlFor="player2Awayteam"> {str("Player2 Awayteam")} </label>
      <input
        name="player2Awayteam"
        onChange={event =>
          dispatch(
            ChangeNamePlayer2Awayteam(ReactEvent.Form.target(event)##value),
          )
        }
      />
    </form>
  </div>;
};

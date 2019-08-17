type screen =
  | GameScreen
  | HometeamScreen
  | AwayScreen;

type players =
  | Player1Hometeam
  | Player2Hometeam
  | Player1Awayteam
  | Player2Awayteam;

type jersey = {
  number: int,
  color: string,
};

type player = {
  name: string,
  picture: string,
  jersey,
};

type order =
  | One
  | Two
  | Three
  | Four;

/* Action declaration */
type action =
  | AddPointsHometeam
  | AddPointsAwayteam
  | ChangeName(player, players)
  | UNDO
  | AddNote(string)
  | ShowView(screen)
  | ServiceOrder(player);

/* State declaration */
type state = {
  scoreH: int,
  scoreA: int,
  player1Hometeam: player,
  player2Hometeam: player,
  player1Awayteam: player,
  player2Awayteam: player,
  notes: list(string),
  actions: list(action),
  screen,
  serviceOrderSet1: list(player),
  serviceOrderSet2: list(player),
  serviceOrderSet3: list(player),
};

type playerInfo = {
  team: string,
  name: string,
  playerString: string,
  fullId: string,
};

let initialState: state = {
  scoreA: 0,
  scoreH: 0,
  player1Hometeam: {
    name: "player1",
    picture: "",
    jersey: {
      number: 1,
      color: "blue",
    },
  },
  player2Hometeam: {
    name: "player2",
    picture: "",
    jersey: {
      number: 2,
      color: "blue",
    },
  },
  player1Awayteam: {
    name: "player1",
    picture: "",
    jersey: {
      number: 1,
      color: "red",
    },
  },
  player2Awayteam: {
    name: "player2",
    picture: "",
    jersey: {
      number: 1,
      color: "blue",
    },
  },

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
  | ChangeName(name, player) =>
    switch (player) {
    | Player1Hometeam => {
        ...state,
        player1Hometeam: {
          ...state.player1Hometeam,
          name: value,
        },
      }
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

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

type page =
  | GamePage
  | EditHP1Page
  | EditHP2Page
  | EditAP1Page
  | EditAP2Page;

type editPlayer =
  | Player
  | Picture
  | Jersey
  | EditNone;

/* Action declaration */
type action =
  | AddPointsHometeam
  | AddPointsAwayteam
  | ChangeName(string, players)
  | ChangeJersey(jersey, players)
  | UNDO
  | AddNote(string)
  | ServiceOrder(players)
  | Edit(editPlayer);

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
  edit: editPlayer,
  serviceOrderSet1: list(players),
  serviceOrderSet2: list(players),
  serviceOrderSet3: list(players),
};

type playerInfo = {
  team: string,
  playerString: string,
  playerStringCap: string,
  fullId: string,
  player,
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
      number: 2,
      color: "blue",
    },
  },

  notes: [],
  actions: [],
  edit: EditNone,
  serviceOrderSet1: [],
  serviceOrderSet2: [],
  serviceOrderSet3: [],
};

let reducer = (state, action) => {
  let state =
    switch (action) {
    | AddPointsHometeam => {...state, scoreH: state.scoreH + 1}
    | AddPointsAwayteam => {...state, scoreA: state.scoreA + 1}
    | ChangeName(name, player) =>
      switch (player) {
      | Player1Hometeam => {
          ...state,
          player1Hometeam: {
            ...state.player1Hometeam,
            name,
          },
        }
      | Player2Hometeam => {
          ...state,
          player2Hometeam: {
            ...state.player2Hometeam,
            name,
          },
        }
      | Player1Awayteam => {
          ...state,
          player1Awayteam: {
            ...state.player1Awayteam,
            name,
          },
        }
      | Player2Awayteam => {
          ...state,
          player2Awayteam: {
            ...state.player2Awayteam,
            name,
          },
        }
      }
    | ChangeJersey(jersey, player) =>
      switch (player) {
      | Player1Hometeam => {
          ...state,
          player1Hometeam: {
            ...state.player1Hometeam,
            jersey,
          },
        }
      | Player2Hometeam => {
          ...state,
          player2Hometeam: {
            ...state.player2Hometeam,
            jersey,
          },
        }
      | Player1Awayteam => {
          ...state,
          player1Awayteam: {
            ...state.player1Awayteam,
            jersey,
          },
        }
      | Player2Awayteam => {
          ...state,
          player2Awayteam: {
            ...state.player2Awayteam,
            jersey,
          },
        }
      }
    | UNDO => {...state, actions: [UNDO, ...state.actions]}
    | AddNote(value) => {...state, notes: [value, ...state.notes]}
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
    | Edit(editPlayer) => {...state, edit: editPlayer}
    };
  Js.log(state);
  state;
};
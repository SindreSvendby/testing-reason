module MenuIcon = MscharleyBsMaterialUiIcons.Menu.Filled;

[@react.component]
let make = (~title: string) => {
  <MaterialUi_AppBar position=`Static>
    <MaterialUi_Toolbar>
      <MaterialUi_IconButton edge=`Start color=`Inherit>
        <MenuIcon />
      </MaterialUi_IconButton>
      <MaterialUi_Typography variant=`H6> title </MaterialUi_Typography>
    </MaterialUi_Toolbar>
  </MaterialUi_AppBar>;
};

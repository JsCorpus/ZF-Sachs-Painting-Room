import { Component, OnInit } from "@angular/core";

//imports para FIrebase
import { TutorialService } from "src/app/services/tutorial.service";
import { Tutorial } from "src/app/models/tutorial.model";
import { map } from 'rxjs/operators'

@Component({
  selector: "app-header-stats",
  templateUrl: "./header-stats.component.html",
})
export class HeaderStatsComponent implements OnInit {
  
  //Datos firebase
  data?: Tutorial[];

  constructor(private tutorialService: TutorialService) { }
  ngOnInit(): void {
    this.retrieveTutorials();
  }
  retrieveTutorials(): void {
    this.tutorialService.getAll().snapshotChanges().pipe(
      map(changes =>
        changes.map(c =>
          ({ key: c.payload.key, ...c.payload.val() })
        )
      )
    ).subscribe(data => {
      this.data = data;
    });
  }
}

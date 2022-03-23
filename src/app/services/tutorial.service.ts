import { Injectable } from '@angular/core';
import { AngularFireDatabase, AngularFireList } from '@angular/fire/database';
import { Tutorial } from '../models/tutorial.model';
@Injectable({
  providedIn: 'root'
})
export class TutorialService {
  private dbPath = '/data';
  tutorialsRef: AngularFireList<Tutorial>;
  constructor(private db: AngularFireDatabase) {
    this.tutorialsRef = db.list(this.dbPath);
  }
  getAll(): AngularFireList<Tutorial> {
    return this.tutorialsRef;
  }
}